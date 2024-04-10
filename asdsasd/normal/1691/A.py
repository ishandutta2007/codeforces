import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    A = list(map(int, input().split()))
    cnt = [0, 0]
    for a in A:
        cnt[a & 1] += 1
    print(min(cnt))
    
    
for _ in range(int(input())):
    solve()