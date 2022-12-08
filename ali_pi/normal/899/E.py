from sys import stdin
from heapq import heappop, heappush, heapify
def main():
    n = int(stdin.readline())
    a = stdin.readline().split()
    q = []
    p = 0
    c = 0
    l = [0] * (n + 1)
    r = [0] * (n + 1)
    k = [0] * (n + 1)
    pa = [0] * (n + 1)
    for i, x in enumerate(a):
        if x == a[p]:
            c += 1
        else:
            l[p] = p - 1
            k[p] = k[i-1] = c
            pa[p] = i - 1
            pa[i-1] = p
            r[i-1] = i
            q.append((-c, p))
            p = i
            c = 1
    q.append((-c, p))
    l[p] = p - 1
    k[p] = k[n-1] = c
    pa[p] = n - 1
    pa[n-1] = p
    r[n-1] = n
    heapify(q)
    ans = 0
    while len(q):
        c, p = heappop(q)
        c = -c
        if k[p] > c:
            continue
        ans += 1
        ls = l[p]
        rs = r[pa[p]]
        if ls >= 0 and rs < n and a[ls] == a[rs]:
            nc = k[ls] + k[rs]
            nl, nr = pa[ls], pa[rs]
            k[nl] = k[nr] = k[ls] = k[rs] = nc
            pa[nr] = nl
            pa[nl] = nr
            heappush(q, (-nc, nl))
        else:
            if ls >= 0:
                r[ls] = rs
            if rs < n:
                l[rs] = ls
    print (ans)
main()