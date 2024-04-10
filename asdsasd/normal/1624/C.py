import sys
input = sys.stdin.readline
from heapq import *

def main():
    n = int(input())
    A = list(map(int, input().split()))
    hq = [-a for a in A]
    heapify(hq)
    i = n
    while hq:
        x = -heappop(hq)
        if x == i:
            i -= 1
        elif x < i:
            print("NO")
            return
        else:
            heappush(hq, -(x // 2))
    print("YES")
    
for _ in range(int(input())):
    main()