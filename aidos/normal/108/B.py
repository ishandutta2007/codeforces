n = int(input())
a = sorted(map(int, input().split()))
ans = 'NO'
for i in range(1, n):
    if a[i-1] * 2 > a[i] and a[i-1] != a[i]:
        ans = 'YES'

print(ans)