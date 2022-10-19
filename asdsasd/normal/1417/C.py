import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    bef = [-1 for _ in range(n)]
    max_d = [-1 for _ in range(n)]
    for i, a in enumerate(alst):
        max_d[a - 1] = max(max_d[a - 1], i - bef[a - 1])
        bef[a - 1] = i
    for i in range(n):
        max_d[i] = max(max_d[i], n - bef[i])
    ans = [-1 for _ in range(n)]
    for i, num in enumerate(max_d):
        for j in range(num - 1, n):
            if ans[j] != -1:
                break
            ans[j] = i + 1
    print(*ans)
    

for _ in range(int(input())):
    main()