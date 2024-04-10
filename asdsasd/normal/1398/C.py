import sys
input = sys.stdin.readline
from collections import defaultdict

def main():
    n = int(input())
    a = input().strip()
    total = 0
    dd = defaultdict(int)
    dd[0] += 1
    for i in range(n):
        total += int(a[i])
        dd[total - i - 1] += 1
    ans = 0
    for _, value in dd.items():
        ans += value * (value - 1) // 2
    print(ans)
    
for _ in range(int(input())):
    main()