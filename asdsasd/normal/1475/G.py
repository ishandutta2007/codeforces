import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    max_ = max(alst) + 1
    cnt = [0] * max_
    for a in alst: cnt[a] += 1
    ans = [0] * max_
    
    for i in range(1, max_):
        ans[i] += cnt[i]
        for j in range(2 * i, max_, i):
            ans[j] = max(ans[j], ans[i])

    print(n - max(ans))
    
for _ in range(int(input())):
    main()