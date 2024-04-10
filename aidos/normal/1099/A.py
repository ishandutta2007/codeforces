ans, h = map(int, input().split())
u1, d1 = map(int, input().split())
u2, d2 = map(int, input().split())
for i in range(h, 0, -1):
    ans += i
    if i == d1:
        ans = max(0, ans-u1)
    elif i == d2:
        ans = max(0, ans-u2)
print(ans)