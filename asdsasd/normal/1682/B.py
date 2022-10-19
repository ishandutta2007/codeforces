import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    P = list(map(int, input().split()))
    ans = (1 << 20) - 1
    for i, p in enumerate(P):
        if i != p:
            ans &= i
    print(ans)

    
for _ in range(int(input())):
    solve()