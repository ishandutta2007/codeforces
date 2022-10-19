import sys
input = sys.stdin.readline
from collections import defaultdict

def main():
    n, k, z = map(int, input().split())
    alst = list(map(int, input().split()))
    rui = [alst[0]]
    for a in alst[1:]:
        rui.append(rui[-1] + a)
    adj = []
    max_adj = 0
    for i in range(n - 1):
        tmp = alst[i] + alst[i + 1]
        max_adj = max(max_adj, tmp)
        adj.append(max_adj)
    adj.append(0)
    ans = 0
    for i in range(z + 1):
        if k - i * 2 < 0:
            break
        tmp = rui[k - i * 2] + i * adj[k - i * 2]
        ans = max(ans, tmp)
    print(ans)
    
    
for _ in range(int(input())):
    main()