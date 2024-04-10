import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    A = list(map(int, input().split()))
    m = int(input())
    B = list(map(int, input().split()))
    print(A[sum(B) % n])

    
    
for _ in range(int(input())):
    solve()