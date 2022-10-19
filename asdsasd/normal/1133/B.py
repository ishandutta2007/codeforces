import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    D = list(map(int, input().split()))
    cnt = [0] * k
    for d in D:
        cnt[d % k] += 1
    ans = 0
    for i in range(1, (k + 1) // 2):
        ans += min(cnt[i], cnt[k - i])
    ans += cnt[0] // 2
    if k % 2 == 0:
        ans += cnt[k // 2] // 2
    print(2 * ans)
    
for _ in range(1):
    main()