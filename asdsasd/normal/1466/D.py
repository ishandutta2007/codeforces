import sys
input = sys.stdin.readline
from heapq import *

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    cnt = [-1 for _ in range(n)]
    for _ in range(n - 1):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        cnt[a] += 1
        cnt[b] += 1
    hq = []
    for a, c in zip(alst, cnt):
        for _ in range(c):
            hq.append(-a)
    heapify(hq)
    total = sum(alst) 
    ans = [total]
    while hq:
        total += -1 * heappop(hq)
        ans.append(total)
    print(*ans)
        
for _ in range(int(input())):
    main()