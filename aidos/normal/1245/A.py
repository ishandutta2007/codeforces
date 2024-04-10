import math

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    if math.gcd(n, m) == 1:
        print('Finite')
    else:
        print('Infinite')