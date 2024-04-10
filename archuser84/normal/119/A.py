import math

arr = input().split()
a = int(arr[0])
b = int(arr[1])
n = int(arr[2])
ans = 1
while n > 0:
    n -= math.gcd(a, n)
    if n == 0:
        ans = 0
    else:
        n -= math.gcd(b, n)
print(ans)