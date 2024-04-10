import sys
input = sys.stdin.readline

def solve():
    n, m = map(int, input().split())
    L = [0] * m
    S = [0] * m
    for i in range(m):
        S[i] = 1
        print("? ", *S, sep="", flush=True)
        L[i] = int(input())
        S[i] = 0
    
    lst = [l * m + i for i, l in enumerate(L)]
    lst.sort()
    S = [1] * m
    print("? ", *S, sep="", flush=True)
    tot = int(input())
    for tmp in lst[1:][::-1]:
        l = tmp // m
        i = tmp - m * l
        S[i] = 0
        print("? ", *S, sep="", flush=True)
        x = int(input())
        if x == tot - l:
            S[i] = 1
        else:
            tot = x
    ans = sum(s * l for l, s in zip(L, S))
    print("!", ans)


    
    
for _ in range(1):
    solve()