import sys
input = sys.stdin.readline
from math import gcd

def main():
    n = int(input())
    A = list(map(int, input().split()))
    prod = 1
    max_ = max(A)
    for i, a in enumerate(A, 2):
        prod = prod * i // gcd(prod, i)
        if prod > max_:
            print("YES")
            return
        if a % prod == 0:
            print("NO")
            return
    print("YES")
    
for _ in range(int(input())):
    main()