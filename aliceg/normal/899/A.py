n = int(input())
a = list(input().split())

m = a.count('2')
k = n - m

if m <= k:
    ans = m
    k -= m
else:
    ans = k
    k = 0

print(ans + k // 3)