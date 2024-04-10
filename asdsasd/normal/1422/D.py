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
    return cost[1]

def main():
    n, m = map(int, input().split())
    sx, sy, fx, fy = map(int, input().split())
    xy = [list(map(int, input().split())) + [i + 2] for i in range(m)]
    edges = [[] for _ in range(m + 2)]
    
    xy.sort(key = lambda x:x[0])
    for i in range(m - 1):
        dx = abs(xy[i][0] - xy[i + 1][0])
        dy = abs(xy[i][1] - xy[i + 1][1])
        d = min(dx, dy)
        pos1 = xy[i][2]
        pos2 = xy[i + 1][2]
        edges[pos1].append((d, pos2))
        edges[pos2].append((d, pos1))
        
    xy.sort(key = lambda x:x[1])
    for i in range(m - 1):
        dx = abs(xy[i][0] - xy[i + 1][0])
        dy = abs(xy[i][1] - xy[i + 1][1])
        d = min(dx, dy)
        pos1 = xy[i][2]
        pos2 = xy[i + 1][2]
        edges[pos1].append((d, pos2))
        edges[pos2].append((d, pos1))
        
    for x, y, i in xy:
        d1 = min(abs(x - sx), abs(y - sy))
        d2 = abs(x - sx) + abs(y - sy)
        edges[0].append((d1, i))
        edges[i].append((d2, 0))
        
        d1 = min(abs(x - fx), abs(y - fy))
        d2 = abs(x - fx) + abs(y - fy)
        edges[1].append((d1, i))
        edges[i].append((d2, 1))
    
    d = abs(sx - fx) + abs(sy - fy)
    edges[0].append((d, 1))
    edges[1].append((d, 0))
    
    ans = dijkstra(m + 2, 0, edges)
    print(ans)
    
    
main()