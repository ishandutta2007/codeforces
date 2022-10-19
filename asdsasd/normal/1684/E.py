import sys
input = sys.stdin.readline

def solve():
    n, K = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort()
    cnt = {}
    for a in A:
        cnt[a] = cnt.get(a, 0) + 1
    
    def ok(x):
        c = 0
        for k in cnt:
            if k < x:
                c += 1
        return x - c <= K
    
    l = 0
    r = n + 1
    while r - l > 1:
        mex = (l + r) // 2
        if ok(mex):
            l = mex
        else:
            r = mex
    mex = l
    ans = len(cnt)
    for k in cnt:
        if k <= mex:
            ans -= 1
    lst = []
    for k, v in cnt.items():
        if k > mex:
            lst.append(v)
    lst.sort()
    for v in lst:
        if v <= K:
            ans -= 1
            K -= v
        else:
            break
    print(ans)

    
for _ in range(int(input())):
    solve()