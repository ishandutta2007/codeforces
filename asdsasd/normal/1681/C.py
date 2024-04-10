import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    ans = []
    for i in range(n):
        for j in range(n - 1, i, -1):
            if A[j] <= A[j - 1] and B[j] <= B[j - 1]:
                ans.append((j, j + 1))
                A[j], A[j - 1] = A[j - 1], A[j]
                B[j], B[j - 1] = B[j - 1], B[j]
    if A == sorted(A) and B == sorted(B):
        print(len(ans))
        for row in ans:
            print(*row)
    else:
        print(-1)

    
    
for _ in range(int(input())):
    solve()