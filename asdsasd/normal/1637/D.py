import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    
    
    dp = [True]
    tot = 0
    max_ = 0
    minus = 0
    for a, b in zip(A, B):
        tot += a + b
        minus += a * a + b * b
        max_ += max(a, b)
        if a > b:
            a, b = b, a
        dp2 = [False] * (max_ + 1)
        for i in range(len(dp)):
            if dp[i]:
                dp2[i + a] = True
                dp2[i + b] = True
        dp = dp2
    ans = 1 << 60
    for i in range(max_ + 1):
        if dp[i]:
            j = tot - i
            ans = min(ans, i * i + j * j)
    print(ans + (n - 2) * minus)
    
    
for _ in range(int(input())):
    main()