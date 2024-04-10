from sys import*
from itertools import*
from collections import*
def main():
    n = int(stdin.readline())
    a = map(int, stdin.readline().split(), repeat(10, n))
    p = map(int, stdin.readline().split(), repeat(10, n - 1))
    e = [[] for _ in xrange(n)]
    for i, x in enumerate(p, 1):
        e[x-1].append(i)
    st = [0]
    pu = st.append
    po = st.pop
    d = [0] * n
    while st:
        x = po()
        for y in e[x]:
            pu(y)
            d[y] = d[x] + 1
    r = max(d)
    d = [(x ^ r) & 1 for x in d]
    s = [0, 0]
    for i, x in enumerate(a):
        s[d[i]] ^= x
    di = [defaultdict(int), defaultdict(int)]
    for i, x in enumerate(a):
        di[d[i]][x] += 1
    ans = 0
    if s[0] == 0:
        l = sum(d)
        ans += l * (l - 1) / 2
        l = n - l
        ans += l * (l - 1) / 2
    for i, x in di[0].viewitems():
        j = i ^ s[0]
        if j in di[1]:
            ans += x * di[1][j]
    print ans
main()