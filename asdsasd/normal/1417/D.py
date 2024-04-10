import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    total = sum(alst)
    if total % n != 0:
        print(-1)
        return
    target = total // n
    ans = []
    for i, a in enumerate(alst[1:], start = 2):
        num = (i - a) % i
        if num != 0:
            ans.append([1, i, num])
            a += num
        ans.append([i, 1, a // i])
    for i, a in enumerate(alst[1:], start = 2):
        ans.append([1, i, target])
    print(len(ans))
    for row in ans:
        print(*row)
    
for _ in range(int(input())):
    main()