import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    S = [input().strip() for _ in range(n)]
    jj = -1
    for i in range(n):
        for j in range(m):
            if S[i][j] == "R":
                if jj == -1:
                    jj = j
                elif j < jj:
                    print("NO")
                    return
    print("YES")
    
    
for _ in range(int(input())):
    main()