import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = [0] + list(map(int, input().split())) + [0]
    ans = 0
    for i in range(1, n + 1):
        if alst[i - 1] < alst[i] and alst[i] > alst[i + 1]:
            ans += alst[i] - max(alst[i + 1], alst[i - 1])
            alst[i] = max(alst[i + 1], alst[i - 1])
    for i in range(n + 1):
        ans += abs(alst[i] - alst[i + 1])
    print(ans)
    
for _ in range(int(input())):
    main()