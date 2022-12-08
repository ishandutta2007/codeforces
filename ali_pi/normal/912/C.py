from sys import stdin
from collections import defaultdict
from itertools import repeat
def main():
    n, m = map(int, stdin.readline().split())
    b, inc, d = map(int, stdin.readline().split())
    dat = map(int, stdin.read().split(), repeat(10, 3 * (n + m)))
    j = n * 3
    ev = [[] for _ in xrange(n)]
    a = defaultdict(int)
    for _ in xrange(m):
        t, i, h = dat[j:j+3]
        ev[i-1].append((t, h))
        j += 3
    j = 0
    c = 0
    for i in xrange(n):
        mh = dat[j]
        reg = dat[j+2]
        ev[i].sort()
        h = dat[j+1]
        p = 0
        on = 0
        if h <= d:
            c += 1
            on = 1
        if reg:
            if mh <= d and inc:
                print -1
                return
            for t, nh in ev[i]:
                if on:
                    x = p + (d - h) / reg + 1
                    if x < t:
                        a[x] -= 1
                        on = 0
                non = nh <= d
                if on != non:
                    a[t] += (-1,1)[non]
                on = non
                p = t
                h = nh
            if on:
                x = p + (d - h) / reg + 1
                a[x] -= 1
        else:
            for t, nh in ev[i]:
                non = nh <= d
                if on != non:
                    a[t] += (-1,1)[non]
                on = non
                p = t
            if on and inc:
                print -1
                return
        j += 3
    ans = c * b
    for t in sorted(a.keys()):
        y = c * (b + (t - 1) * inc)
        if ans < y:
            ans = y
        c += a[t]
    print ans
main()