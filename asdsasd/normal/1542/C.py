import sys
input = sys.stdin.readline
MOD = 10 ** 9 + 7
from math import gcd

def main():
    n = int(input())
    ans = 0
    N = n
    p = 2
    prod = 2
    while N:
        ans += (N - n // prod) * p
        N = n // prod
        p += 1
        prod = prod * p // gcd(prod, p)
    print(ans % MOD)
    
for _ in range(int(input())):
    main()