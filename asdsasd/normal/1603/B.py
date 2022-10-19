import sys
input = sys.stdin.readline
from math import gcd

def main():
    x, y = map(int, input().split())
    if x == y:
        n = x
    elif x > y:
        n = x + y
    else:
        ave = (x + y) // 2
        n = ave + (y - ave) // x * x
    print(n)
    assert n % x == y % n, (x, y, n)
    
for _ in range(int(input())):
    main()