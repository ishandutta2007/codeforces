import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    alst = list(map(int, input().split()))
    cnt = [0] * m
    for a in alst:
        cnt[a % m] += 1
    ans = 0
    for i in range(1, (m + 1) // 2):
        min_ = min(cnt[i], cnt[m - i])
        max_ = max(cnt[i], cnt[m - i])
        if min_ == max_ == 0:
            continue
        else:
            ans += max(1, max_ - min_)
    if cnt[0] > 0:
        ans += 1
    if m % 2 == 0 and cnt[m // 2] > 0:
        ans += 1
    print(ans)
            
    
    
for _ in range(int(input())):
    main()