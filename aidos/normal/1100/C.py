import math
n, r = map(int, input().split())
pi = math.pi
a = pi * (n-2)/n

print(r * (math.cos(a/2))/(1-math.cos(a/2)))