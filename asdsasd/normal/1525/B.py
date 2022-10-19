import sys
input = sys.stdin.readline
from math import gcd

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    if all(i == a for i, a in enumerate(alst, 1)):
        print(0)
    elif alst[0] == 1 or alst[-1] == n:
        print(1)
    elif alst[0] == n and alst[-1] == 1:
        print(3)
    else:
        print(2)
    
    
for _ in range(int(input())):
    main()