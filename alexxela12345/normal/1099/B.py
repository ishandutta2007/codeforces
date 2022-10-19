from math import sqrt
n = int(input())
sq = int(sqrt(n))
print(sq + (n + sq - 1) // sq)