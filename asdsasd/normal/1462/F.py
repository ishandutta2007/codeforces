import sys
input = sys.stdin.readline
from bisect import bisect_right, bisect_left

def main():
    n = int(input())
    lr = []
    l_s = []
    r_s = []
    for _ in range(n):
        l, r = map(int, input().split())
        lr.append((l, r))
        l_s.append(l)
        r_s.append(r)
    l_s.sort()
    r_s.sort()
    ans = n
    for l, r in lr:
        pos1 = bisect_left(r_s, l)
        pos2 = bisect_right(l_s, r)
        ans = min(ans, pos1 + n - pos2)
    print(ans)
    
    
    
for _ in range(int(input())):
    main()