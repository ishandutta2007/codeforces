import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    exist = [False for _ in range(n + 1)]
    for i in range(n):
        total = alst[i]
        for j in range(i + 1, n):
            total += alst[j]
            if total > n:
                break
            exist[total] = True
    cnt = 0
    for a in alst:
        if exist[a]:
            cnt += 1
    print(cnt)
for _ in range(int(input())):
    main()