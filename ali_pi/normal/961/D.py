from itertools import combinations
from fractions import gcd

def main():
    n = input()
    p = [list(map(int,raw_input().split())) for _ in range(n)]
    print(solve(n, p))

def solve(n, p):
    if n < 5:
        return "YES"
    p5 = p[:5]
    lines = set(line(p1, p2) for p1, p2 in combinations(p5, 2))
    l0 = None
    for l in lines:
        if nb_points(l, p5) > 2:
            l0 = l
            break
    if l0 is None:
        return "NO"
    pr = [pi for pi in p if not belongs(pi, l0)]
    if colinear(pr):
        return "YES"
    return "NO"

def line(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    a = y2 - y1
    b = x1 - x2
    c = x2 * y1 - x1 * y2
    if a < 0:
        a, b, c = -a, -b, -c
    if a == 0:
        if b < 0:
            b, c = -b, -c
        if c == 0:
            b = 1
        else:
            g = abs(gcd(b, c))
            b, c = b // g, c // g
    else:
        if b == 0:
            if c == 0:
                a = 1
            else:
                g = abs(gcd(a, c))
                a, c = a // g, c // g
        else:
            if c == 0:
                g = abs(gcd(a, b))
                a, b = a // g, b // g
            else:
                g = abs(gcd(gcd(a, b), c))
                a, b, c = a // g, b // g, c // g
    return a, b, c

def belongs(pi, l):
    a, b, c = l
    return a * pi[0] + b * pi[1] + c == 0

def nb_points(l, p):
    return sum(1 for pi in p if belongs(pi, l))

def colinear(p):
    if len(p) <= 2:
        return True
    l = line(p[0], p[1])
    return all(belongs(pi, l) for pi in p[2:])

main()