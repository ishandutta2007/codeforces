import sys
import math

input = sys.stdin.readline

tt = int(input())

for _ in range(tt):
    n, m, k = map(int, input().split())
    mx = n * m - 1
    if (k == mx):
        print("YES")
    else:
        print("NO")