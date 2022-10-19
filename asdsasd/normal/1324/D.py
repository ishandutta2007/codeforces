import sys
input = sys.stdin.readline
from bisect import bisect_left

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    blst = list(map(int, input().split()))
    clst = [-(a - b) for a, b in zip(alst, blst)]
    clst.sort()
    ans = 0
    for a, b in zip(alst, blst):
        ans += bisect_left(clst, a - b)
        if a - b > -(a - b):
            ans -= 1
    print(ans // 2)
    
    
for _ in range(1):
    main()