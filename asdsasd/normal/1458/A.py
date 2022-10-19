import sys
input = sys.stdin.readline
from math import gcd

def main():
    n, m = map(int, input().split())
    alst = list(map(int, input().split()))
    blst = list(map(int, input().split()))
    g = 0
    for i in range(n - 1):
        g = gcd(g, alst[i + 1] - alst[i])
    a = alst[0]
    ans = [gcd(g, b + a) for b in blst]
    print(*ans)
    
    
for _ in range(1):
    main()