import sys
input = sys.stdin.readline
from collections import defaultdict

def main():
    n, k = map(int, input().split())
    A = input().strip()
    B = input().strip()
    cnt_a = [0 for _ in range(26)]
    cnt_b = [0 for _ in range(26)]
    for a in A:
        cnt_a[ord(a) - ord("a")] += 1
    for b in B:
        cnt_b[ord(b) - ord("a")] += 1
    total = 0
    for a, b in zip(cnt_a, cnt_b):
        if (a - b) % k != 0:
            print("No")
            return
        total += a - b
        if total < 0:
            print("No")
            return
    else:
        print("Yes")
    
    
for _ in range(int(input())):
    main()