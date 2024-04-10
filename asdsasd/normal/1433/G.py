import sys
input = sys.stdin.readline

import heapq

def dijkstra(n, s, edges):
    hq = [(0, s)]
    cost = [float('inf')] * n
    cost[s] = 0
    while hq:
        c, v = heapq.heappop(hq)
        if c > cost[v]:
            continue
        for d, u in edges[v]:
            tmp = d + cost[v]
            if tmp < cost[u]:
                cost[u] = tmp
                heapq.heappush(hq, (tmp, u))
    return cost

def main():
    n, m, k = map(int, input().split())

    edges = [[] for _ in range(n)]
    xy = []
    for _ in range(m):
        x, y, t = map(int,input().split())
        x -= 1
        y -= 1
        edges[x].append((t, y))
        edges[y].append((t, x))
        xy.append((x, y))
    
    dist = [[] for _ in range(n)]
    for i in range(n):
        dist[i] = dijkstra(n, i, edges)
        
    ab = [list(map(int, input().split())) for _ in range(k)]
    ans = 10 ** 20
    for x, y in xy:
        tmp = 0
        for a, b in ab:
            a -= 1
            b -= 1
            tmp += min(dist[a][b], dist[a][x] + dist[b][y], dist[a][y] + dist[b][x])
        ans = min(ans, tmp)
    print(ans)
    
main()