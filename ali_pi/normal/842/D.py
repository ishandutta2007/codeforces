from sys import*
from itertools import*
def main(bi=bin):
    n, m = map(int, stdin.readline().split())
    a = map(int, stdin.read().split(), repeat(10, n + m))
    N = 1 << 19
    t = [0] * (N + N)
    for x in set(a[:n]):
        t[x+N] = 1
    for x in xrange(N - 1, 0, -1):
        t[x] = t[x+x] & t[x+x+1]
    s = 0
    ans = []
    aa = ans.append
    for x in a[n:]:
        s ^= x
        r = 1
        for c in bi(s)[2:].zfill(19):
            r += r
            if c == "1":
                r += t[r^1] ^ 1
            else:
                r += t[r]
        aa((r ^ s) - N)
    stdout.write('\n'.join(map(str, ans)))
main()