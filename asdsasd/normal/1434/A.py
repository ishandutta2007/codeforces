import heapq
import sys
input = sys.stdin.readline

def main():
    alst = list(map(int, input().split()))
    n = int(input())
    blst = list(map(int, input().split()))
    alst.sort(reverse = True)
    blst.sort()
    lst = []
    for b in blst:
        tmp = [b - a for a in alst]
        lst.append(tmp)
    hq = []
    max_ = 0
    for i in range(n):
        hq.append((lst[i][0], i, 0))
        max_ = max(max_, lst[i][0])
    heapq.heapify(hq)
    ans = max_ - hq[0][0]
    while 1:
        _, i, pos = heapq.heappop(hq)
        if pos == 5:
            break
        max_ = max(max_, lst[i][pos + 1])
        heapq.heappush(hq, (lst[i][pos + 1], i, pos + 1))
        ans = min(ans, max_ - hq[0][0])
    print(ans)
main()