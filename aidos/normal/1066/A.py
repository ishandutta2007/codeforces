t = int(input())
for i in range(t):
    L, v, l, r = map(int, input().split())
    ans = L//v
    ans -= r//v
    ans += (l-1)//v
    print(ans)