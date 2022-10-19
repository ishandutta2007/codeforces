import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    S = list(map(int, input().strip()))
    tot = sum(S)
    if tot & 1 or tot == 0:
        print("NO")
        return
    print("YES")
    ind = S.index(1)
    S = S[ind+1:] + S[:ind+1]
    
    i = 1
    p = 0
    ii = i + ind + 1
    p += ind + 1
    ii %= n
    p %= n
    print(ii + 1, p + 1)

    for i in range(2, n):
        if S[i - 1] == 1:
            p = 0
        else:
            p = i - 1

        ii = i + ind + 1
        p += ind + 1
        ii %= n
        p %= n
        print(ii + 1, p + 1)
        
        
    
    

    
for _ in range(int(input())):
    solve()