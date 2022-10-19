import sys
input = sys.stdin.readline

def solve():
    n, m = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(n)]
    L = [-1] * m
    R = [m] * m
    for row in A:
        B = sorted(row)
        l = {}
        r = {}
        bef = -1
        for i, b in enumerate(B):
            if b != bef:
                l[b] = i
                bef = b
            r[b] = i
        for i, a in enumerate(row):
            L[i] = max(L[i], l[a])
            R[i] = min(R[i], r[a])
    
    lst = []
    for i, (l, r) in enumerate(zip(L, R)):
        if r < l:
            print(-1)
            return
        elif i < l or i > r:
            lst.append(i)
    if not lst:
        print(1, 1)
        return
    elif len(lst) >= 3:
        print(-1)
        return
    elif len(lst) == 2:
        i1, i2 = lst        
        if L[i1] <= i2 <= R[i1] and L[i2] <= i1 <= R[i2]:
            print(i1 + 1, i2 + 1)
        else:
            print(-1)
    else:
        i1 = lst[0]
        for i2 in range(n):
            if L[i1] <= i2 <= R[i1] and L[i2] <= i1 <= R[i2]:
                print(i1 + 1, i2 + 1)
                return
        print(-1)





    
    
for _ in range(int(input())):
    solve()