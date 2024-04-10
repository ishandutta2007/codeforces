import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    lst = []
    for i in range(n):
        bs = list(map(int, input().split()))
        for b in bs:
            lst.append((b, i))
    lst.sort()
    ans = [[-1] * m for _ in range(n)]
    for j in range(m):
        b, i = lst[j]
        ans[i][j] = b
    
    pos = [0] * n
    for b, i in lst[m:]:
        while ans[i][pos[i]] != -1:
            pos[i] += 1
        ans[i][pos[i]] = b
        pos[i] += 1
        
    
    for row in ans:
        print(*row)
    
    
for _ in range(int(input())):
    main()