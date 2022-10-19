import sys
input = sys.stdin.readline

def main():
    n = int(input())
    W = list(map(int, input().split()))
    L = {}
    tot = 0
    for i, s in enumerate(W, 1):
        tot += s
        L[tot] = i
        
    ans = 0
    tot = 0
    for i in range(n - 1, -1, -1):
        tot += W[i]
        if tot in L:
            x = (n - i) + L[tot]
            if x <= n:
                ans = max(ans, x)
            else:
                break
    print(ans)
        
    
    
for _ in range(int(input())):
    main()