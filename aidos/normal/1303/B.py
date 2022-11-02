def good(x, n, g, b):
    z = x//(g+b)
    e = z * g
    f = z * b
    if x % (g+b) <= g:
        e += x % (g+b)
    else:
        e += g
        f += x % (g+b)-g
    if e < (n+1)//2:
        return 0
    if e + f >= n:
        return 1
    return 0


t = int(input())
for _ in range(t):
    n, g, b = map(int, input().split())
    l = 0
    r = 10**20
    res = -1
    while l <= r:
        mid = (l + r)//2
        if good(mid, n, g, b):
            r = mid-1
            res = mid
        else:
            l = mid+1
    print(res)