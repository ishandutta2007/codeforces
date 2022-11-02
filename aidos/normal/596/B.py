n = int(input())
a = list(map(int, input().split()))
s = 0
ans = 0
for i in range(n):
    a[i] += s
    ans += abs(a[i])
    s -= a[i]
print(ans)