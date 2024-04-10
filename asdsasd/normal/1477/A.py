import sys
input = sys.stdin.readline
from math import gcd

def main():
    n, k = map(int, input().split())
    xlst = list(map(int, input().split()))
    g = 0
    x0 = xlst[0]
    for x in xlst:
        g = gcd(g, x - x0)
    if(k - x0) % g == 0:
        print("YES")
    else:
        print("NO")
    
    
for _ in range(int(input())):
    main()