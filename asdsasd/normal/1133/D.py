import sys
input = sys.stdin.readline
from math import gcd

def main():
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    cnt = {0:0}
    ans = 0
    for a, b in zip(A, B):
        if a == b == 0:
            ans += 1
            continue
        elif a == 0:
            continue
        g = gcd(a, b)
        a //= g
        b //= g
        if a < 0:
            a *= -1
            b *= -1
        elif a == 0 and b < 0:
            b *= -1
        cnt[(a, b)] = cnt.get((a, b), 0) + 1
    print(ans + max(cnt.values()))
    
for _ in range(1):
    main()