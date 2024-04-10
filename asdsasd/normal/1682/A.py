import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    S = input().strip()
    
    T = S[n // 2:]
    bef = T[0]
    cnt = 0
    for t in T:
        if t == bef:
            cnt += 2
        else:
            break
    cnt -= n & 1
    print(cnt)
    
    
    
for _ in range(int(input())):
    solve()