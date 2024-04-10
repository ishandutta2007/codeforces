from collections import defaultdict
import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    dd = defaultdict(int)
    for a in alst:
        dd[a] += 1
    cnt = [0] * (n + 1)
    for _, v in dd.items():
        cnt[v] += 1
    for i in range(n - 1, -1, -1):
        cnt[i] += cnt[i + 1]
    max_ = 0
    for i, c in enumerate(cnt):
        max_ = max(max_, i * c)
    print(n - max_)
    
    
for _ in range(int(input())):
    main()