import sys
input = sys.stdin.readline
from collections import defaultdict

def main():
    S = input().strip()
    cnt = [0] * 26
    for s in S:
        cnt[ord(s) - 97] += 1
    ans = 0
    for c in cnt:
        ans += min(c, 2)
    print(ans // 2)
    
for _ in range(int(input())):
    main()