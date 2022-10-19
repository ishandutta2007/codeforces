# i \in [0, x), j \in [0, y), i + j <= z
#  (i, j) 
def leq_cnt(x, y, z):
    if z < 0:
        return 0
    if z >= x + y - 2:
        return x * y

    l1 = z - x + 1
    l2 = z + 1
    if l1 >= 0:
        ret = l1 * x
        ret += x * (x + 1) // 2
    else:
        ret = (z + 1) * (z + 2) // 2
    if l2 >= y:
        ret -= (z - y + 2) * (z - y + 1) // 2
    return ret

def solve():
    n = int(input())
    P = list(map(int, input().split()))
    invP = [0] * n
    for i, p in enumerate(P):
        invP[p] = i

    ans = 1
    l = n
    r = -1
    for i in range(n - 1):
        l = min(l, invP[i])
        r = max(r, invP[i])
        nex = invP[i + 1]
        if l < nex < r:
            continue
        if nex < l:
            dl = l - nex
            dr = n - r
        else:
            dl = l + 1
            dr = nex - r
        d = r - l + 1
        okd = 2 * (i + 1)
        rd = okd - d
        ans += leq_cnt(dl, dr, rd)
    print(ans)



for _ in range(int(input())):
    solve()