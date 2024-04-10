import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    cnt = [0 for _ in range(n + 1)]
    for a in alst:
        cnt[a] += 1
    if max(cnt) > (n + 1) / 2:
        print(-1)
        return
    
    ans = 0
    end = [0 for _ in range(n + 1)]
    for i in range(n - 1):
        if alst[i] == alst[i + 1]:
            end[alst[i]] += 1
            end[alst[i + 1]] += 1
            ans += 1
    end[alst[0]] += 1
    end[alst[-1]] += 1
    print(ans + max(0, max(end) - ans - 2))
    
for _ in range(int(input())):
    main()