import sys
input = sys.stdin.readline

def solve():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    if n <= k:
        print(sum(A) + (k + k - n - 1) * n // 2)
        return
    cum = [0]
    for a in A:
        cum.append(cum[-1] + a)
    ans = 0
    for i in range(k, n + 1):
        ans = max(ans, cum[i] - cum[i - k])
    ans += (k - 1) * k // 2
    print(ans)
    
    
for _ in range(int(input())):
    solve()