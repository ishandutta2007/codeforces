import sys
input = sys.stdin.readline
from math import gcd

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        for j in range(i + 1, n):
            if alst[i] % 2 == 0 or alst[j] % 2 == 0:
                ans += 1
            elif gcd(alst[i], 2 * alst[j]) > 1:
                ans += 1
    print(ans)
    
    
for _ in range(int(input())):
    main()