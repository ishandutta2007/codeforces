import math
n = int(input())
a = n//2
b = n-a
while math.gcd(a, b) > 1:
    a -= 1
    b += 1
print(a, b)