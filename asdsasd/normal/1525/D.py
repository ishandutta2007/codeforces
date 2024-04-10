import sys
input = sys.stdin.readline

def main():
    n = int(input())            
    alst = list(map(int, input().split()))
    zero = []
    one = []
    for i, a in enumerate(alst):
        if a == 0:
            zero.append(i)
        else:
            one.append(i)
    inf = n * n
    dp = [[inf] * (len(one) + 1) for _ in range(len(zero) + 1)]
    for i in range(len(zero) + 1): dp[i][0] = 0
    for i, z in enumerate(zero, 1):
        for j, o in enumerate(one, 1):
            dp[i][j] = min(dp[i - 1][j] , dp[i - 1][j - 1] + abs(z - o))
    
    print(dp[-1][-1])
            
    
    
    
for _ in range(1):
    main()