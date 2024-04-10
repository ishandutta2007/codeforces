n, x = map(int, input().split())
a = list(map(int, input().split()))
ans = a.count(x)
for i in range(x):
    if i not in a:
        ans += 1
print(ans)