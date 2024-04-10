import sys
input = sys.stdin.readline
from math import gcd

def main():
    k = int(input())
    g = gcd(k, 100 - k)
    print(100 // g)
    
    
for _ in range(int(input())):
    main()