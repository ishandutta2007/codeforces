import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    ans = [-1] * n
    def dfs(l, r, cnt):
        if r < l:
            return
        max_pos = alst.index(max(alst[l:r + 1]))
        ans[max_pos] = cnt
        dfs(l, max_pos - 1, cnt + 1)
        dfs(max_pos + 1, r, cnt + 1)
        
    dfs(0, n - 1, 0)
    print(*ans)
    
for _ in range(int(input())):
    main()