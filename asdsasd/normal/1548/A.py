import sys
input = sys.stdin.readline
from heapq import *


def main():
    n, m = map(int, input().split())
    hq = [[] for _ in range(n)]
    rem = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        heappush(hq[u], -v)
        heappush(hq[v], -u)
    ans = n
    for i in range(n):
        if hq[i] and -hq[i][0] > i:
            ans -= 1
    q = int(input())
    for _ in range(q):
        query = list(map(int, input().split()))
        if query[0] == 1:
            _, u, v = query
            u -= 1
            v -= 1
            if hq[u] and -hq[u][0] > u:
                ans += 1
            if hq[v] and -hq[v][0] > v:
                ans += 1
            heappush(hq[u], -v)
            heappush(hq[v], -u)
            if hq[u] and -hq[u][0] > u:
                ans -= 1
            if hq[v] and -hq[v][0] > v:
                ans -= 1
        elif query[0] == 2:
            _, u, v = query
            u -= 1
            v -= 1
            if hq[u] and -hq[u][0] > u:
                ans += 1
            if hq[v] and -hq[v][0] > v:
                ans += 1
            heappush(rem[u], -v)
            heappush(rem[v], -u)
            while rem[u] and rem[u][0] == hq[u][0]:
                heappop(rem[u])
                heappop(hq[u])
            while rem[v] and rem[v][0] == hq[v][0]:
                heappop(rem[v])
                heappop(hq[v])
            if hq[u] and -hq[u][0] > u:
                ans -= 1
            if hq[v] and -hq[v][0] > v:
                ans -= 1
        else:
            print(ans)
    
for _ in range(1):
    main()