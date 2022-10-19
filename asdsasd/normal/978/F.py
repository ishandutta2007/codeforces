import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    R = list(map(int, input().split()))
    S = [(r, i) for i, r in enumerate(R)]
    S.sort()
    ans = [0] * n
    br = 0
    c = 0
    for i, (r, j) in enumerate(S):
        if br != r:
            br = r
            c = i
        ans[j] = c
    
    for _ in range(k):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        if R[x] == R[y]:
            continue
        elif R[x] < R[y]:
            ans[y] -= 1
        else:
            ans[x] -= 1
        
    
    print(*ans)
        
    
for _ in range(1):
    main()