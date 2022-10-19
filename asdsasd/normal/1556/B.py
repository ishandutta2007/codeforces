import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    inf = 10 ** 10
    ans = inf
    odd = 0
    even = 0
    # 01010101
    for i, a in enumerate(alst):
        if i % 2 == 0 and a % 2 == 1:
            odd += 1
        elif i % 2 == 1 and a % 2 == 0:
            even += 1
    if odd == even:
        tmp = 0
        x = 0
        for i, a in enumerate(alst):
            if a % 2 == 0:
                tmp += abs(i - x)
                x += 2
        ans = min(ans, tmp)
    odd = 0
    even = 0
    for i, a in enumerate(alst):
        if i % 2 == 0 and a % 2 == 0:
            odd += 1
        elif i % 2 == 1 and a % 2 == 1:
            even += 1
    if odd == even:
        tmp = 0
        x = 0
        for i, a in enumerate(alst):
            if a % 2 == 1:
                tmp += abs(i - x)
                x += 2
        ans = min(ans, tmp)
        
    if ans == inf:
        print(-1)
    else:
        print(ans)
for _ in range(int(input())):
    main()