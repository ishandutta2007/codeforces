from math import cos, radians
n, r = list(map(int, input().split()))
deg = (n - 2) * 90 / n
cc = cos(radians(deg))
print((cc * r / (1 - cc)))