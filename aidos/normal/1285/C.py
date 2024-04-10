import math

x = int(input())
ans = x
for i in range(10**6, 0, -1):
    if x % i == 0 and math.gcd(i, x//i) == 1:
        ans = min(ans, max(i, x//i))
print(x//ans, ans)