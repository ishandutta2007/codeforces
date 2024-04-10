def solve():
    n = int(input())
    alst = list(map(int, input().split()))
    alst.sort()
    bef = alst[0]
    for a in alst:
        if a - bef >= 2:
            print("NO")
            return
        bef = a
    print("YES")
    return
    
    

t = int(input())
for _ in range(t):
    solve()