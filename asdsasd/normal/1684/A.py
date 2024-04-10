import sys
input = sys.stdin.readline

def solve():
    A = list(map(int, input().strip()))
    if len(A) == 2:
        print(A[1])
    else:
        print(min(A))
    
for _ in range(int(input())):
    solve()