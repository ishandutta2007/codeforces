import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    A = list(map(int, input().split()))
    m = int(input())
    B = list(map(int, input().split()))
    ma_a = max(A)
    ma_b = max(B)
    if ma_a > ma_b:
        print("Alice")
        print("Alice")
    elif ma_a == ma_b:
        print("Alice")
        print("Bob")
    else:
        print("Bob")
        print("Bob")

    
    
for _ in range(int(input())):
    solve()