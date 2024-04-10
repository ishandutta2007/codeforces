import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    cnt = [0, 0, 0]
    for a in alst:
        cnt[a % 3] += 1
    ans = 0
    x = n // 3
    for _ in range(3):
        for i in range(3):
            if cnt[i] > x:
                cnt[(i + 1) % 3] += cnt[i] - x
                ans += cnt[i] - x
                cnt[i] = x
    print(ans)
    
for _ in range(int(input())):
    main()