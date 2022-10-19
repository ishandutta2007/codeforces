import sys
input = sys.stdin.readline

def main():
    input()    
    n = int(input())
    A = [list(map(int, input().strip())) for _ in range(n)]
    cnt = 0
    ma = 0
    for i in range(n):
        ii = i
        j = 0
        tot = 0
        for _ in range(n):
            if A[ii][j] == 1:
                cnt += 1
                tot += 1
            ii += 1
            if ii == n:
                ii = 0
            j += 1
        if tot > ma:
            ma = tot
    print(n - ma + cnt - ma)
        
        
            
    
    
for _ in range(int(input())):
    main()