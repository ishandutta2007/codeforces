import sys
input = sys.stdin.readline
from math import gcd

def ok(n):
    m = sum(map(int, str(n)))
    return gcd(m, n) > 1

def main():
    n = int(input())
    while 1:
        if ok(n):
            print(n)
            return
        n += 1
    
for _ in range(int(input())):
    main()