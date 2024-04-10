import sys
input = sys.stdin.readline
from math import gcd

def main():
    n = int(input())
    A = list(map(int, input().split()))
    if n <= 2:
        print(0)
        return
    ans = n
    for l in range(n - 1):
        for r in range(l + 1, n):
            dx = r - l
            da = A[r] - A[l]
            g = gcd(dx, da)
            dx //= g
            da //= g
            mi = l % dx
            mm = A[l] - da * (l // dx)
            tmp = n
            for i in range(mi, n, dx):
                if A[i] == mm:
                    tmp -= 1
                mm += da
            ans = min(ans, tmp)
    print(ans)
    
    
for _ in range(int(input())):
    main()