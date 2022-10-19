import sys
input = sys.stdin.readline
from bisect import bisect_left

def main():
    n, q = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort(reverse = True)
    for i in range(1, n):
        A[i] += A[i - 1]
    for _ in range(q):
        x = int(input())
        p = bisect_left(A, x)
        if p == n:
            print(-1)
        else:
            print(p + 1)

for _ in range(int(input())):
    main()