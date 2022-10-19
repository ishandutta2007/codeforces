def solve():
    n = int(input())
    alst = list(map(int, input().split()))
    blst = list(map(int, input().split()))
    a_min = min(alst)
    b_min = min(blst)
    ans = 0
    for a, b in zip(alst, blst):
        ans += max(a - a_min, b - b_min)
    print(ans)
    

t = int(input())
for _ in range(t):
    solve()