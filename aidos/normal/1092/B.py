n = int(input())
a = list(map(int, input().split()))
a = sorted(a)
ans = 0
for i in range(n//2):
    ans += a[i*2+1]-a[i * 2]
print(ans)