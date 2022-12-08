from sys import stdin
from itertools import repeat
def get(p, k):
    res = 0
    for d, s in p:
        t = k if s > k else s
        res += d * t
        k -= t
    return res
def main():
    n, S = map(int, stdin.readline().split())
    dat = map(int, stdin.read().split(), repeat(10, 3 * n))
    ss = h = 0
    j = 0
    po = [[], [], []]
    cn = [0] * 3
    for i in xrange(n):
        s, a, b = dat[j:j+3]
        ss += s
        sgn = cmp(a, b)
        po[sgn].append(((a - b) * sgn, s))
        cn[sgn] += s
        h += ((a, a, b)[sgn]) * s
        j += 3
    po[1].sort()
    po[-1].sort()
    t = (ss + S - 1) / S
    r = t * S - ss
    if cn[1] % S + cn[0] + r < S:
        x = get(po[1], cn[1] % S)
        y = get(po[-1], cn[-1] % S)
        h -= min(x, y)
    print(h)
main()