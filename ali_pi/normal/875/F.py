from sys import stdin
from itertools import repeat
def main():
    n, m = map(int, stdin.readline().split())
    dat = map(int, stdin.read().split(), repeat(10, 3 * m))
    e = [(-dat[i*3+2], dat[i*3+1], dat[i*3]) for i in xrange(m)]
    e.sort()
    par = range(n + 1)
    c = [1] * (n + 1)
    st = []
    po = st.pop
    pu = st.append
    ans = 0
    for s, x, y in e:
        while x != par[x]:
            pu(x)
            x = par[x]
        while y != par[y]:
            pu(y)
            y = par[y]
        if x == y:
            if c[y]:
                c[y] = 0
                ans += s
        else:
            pu(x)
            if c[y] or c[x]:
                ans += s
            c[y] &= c[x]
            for z in st:
                par[z] = y
        del st[:]
    print -ans
main()