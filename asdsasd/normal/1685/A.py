import sys
input = sys.stdin.readline
from heapq import *

def solve():
    n = int(input())
    A = list(map(int, input().split()))
    if n & 1:
        print("NO")
        return
    A.sort()
    bef = A[:n//2]
    aft = A[n//2:]
    B = []
    for b, a in zip(bef, aft):
        B += [b, a]
    for i in range(n):
        if i != 0:
            i1 = i - 1
        else:
            i1 = n - 1
        if i != n - 1:
            i2 = i + 1
        else:
            i2 = 0
        if B[i] == B[i1] or B[i] == B[i2]:
            print("NO")
            return
        if (B[i] > B[i1]) ^ (B[i] > B[i2]):
            print("NO")
            return
    print("YES")
    print(*B)
    
for _ in range(int(input())):
    solve()