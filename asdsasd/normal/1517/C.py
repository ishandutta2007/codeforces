import sys
input = sys.stdin.readline

def main():
    n = int(input())
    plst = list(map(int, input().split()))
    ans = [[-1] * n for _ in range(n)]
    
    def nex(ii, jj):
        if jj == 0:
            return ii + 1, jj
        elif ans[ii][jj - 1] == -1:
            return ii, jj - 1
        else:
            return ii + 1, jj
    
    for i, p in enumerate(plst):
        ans[i][i] = p
        ii, jj = i, i
        for _ in range(p - 1):
            while ans[ii][jj] != -1:
                ii, jj = nex(ii, jj)
            ans[ii][jj] = p
    for i in range(n):
        print(*ans[i][:i + 1])
        
for _ in range(1):
    main()