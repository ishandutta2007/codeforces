import sys
input = sys.stdin.readline


def nCk(n, k):
    if k > n or k < 0:
        return 0
    k = min(k, n - k)
    ret = 1
    for i in range(n, n - k, -1):
        ret *= i
    for i in range(2, k + 1):
        ret //= i
    return ret
    
def main():
    n = int(input())
    m = 3
    k = 2
    alst = list(map(int, input().split()))
    alst.sort()
    alst += [float("inf")]
    r = 0
    ans = 0
    for l in range(n):
        while alst[r] - alst[l] <= k:
            r += 1
        ans += nCk(r - l - 1, m - 1)
        
    print(ans)
    
for _ in range(int(input())):
    main()