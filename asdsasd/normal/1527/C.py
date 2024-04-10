import sys
input = sys.stdin.readline
from collections import defaultdict as dd

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    cnt = dd(int)
    ans = 0
    for i, a in enumerate(alst):
        ans += cnt[a] * (n - i)
        cnt[a] += i + 1
    print(ans)
    
for _ in range(int(input())):
    main()