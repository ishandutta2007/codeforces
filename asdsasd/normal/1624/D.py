import sys
input = sys.stdin.readline
from heapq import *

def main():
    n, k = map(int, input().split())
    S = input().strip()
    cnt = [0] * 26
    for s in S:
        cnt[ord(s) - 97] += 1
    one = 0
    two = 0
    for c in cnt:
        if c % 2 == 1:
            one += 1
        two += c // 2
    if one >= k:
        print(1 + two // k * 2)
    else:
        ans1 = two // k * 2
        ans2 = 1 + (two * 2 - k + one) // 2 // k * 2
        print(max(ans1, ans2))
    
for _ in range(int(input())):
    main()