import sys
input = sys.stdin.readline
from collections import defaultdict

def main():
    n, k = map(int, input().split())
    alst = list(map(int, input().split()))
    dd = defaultdict(list)
    for i, a in enumerate(alst):
        dd[a].append(i)
    ans = [0] * n
    tot = 0
    for _, v in dd.items():
        tot += min(len(v), k)
    tot = tot // k * k
    for _, v in dd.items():
        if len(v) >= k:
            for i in v[:k]:
                if tot == 0:
                    break
                ans[i] = (tot % k) + 1
                tot -= 1
        else:
            for i in v:
                if tot == 0:
                    break
                ans[i] = (tot % k) + 1
                tot -= 1
                
    print(*ans)
    
    
    
    
for _ in range(int(input())):
    main()