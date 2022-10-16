import sys
import math

input = sys.stdin.readline

tt = int(input())

for _ in range(tt):
    r, b, d = map(int, input().split())
    if r < b: 
        tmp = b
        b = r
        r = tmp
    num = (r + b - 1) // b
    if (num - 1 <= d): 
        print("YES")
    else:
        print("NO")