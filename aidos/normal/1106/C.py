n = int(input())
a = sorted(map(int, input().split()))
ans = 0
for i in range(n//2):
    ans += (a[i] + a[n-i-1]) ** 2
print(ans)