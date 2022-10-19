import sys
input = sys.stdin.readline

def main():
    n, t = map(int, input().split())
    alst = list(map(int, input().split()))
    lst = [[i, a] for i, a in enumerate(alst)]
    lst.sort()
    if t % 2 == 0:
        mid = t // 2
    else:
        mid = t / 2
    ans = [-1 for _ in range(n)]
    flg = False
    for i, a in lst:
        if a < mid:
            ans[i] = 0
        elif a > mid:
            ans[i] = 1
        elif flg:
            flg = False
            ans[i] = 0
        else:
            flg = True
            ans[i] = 1
    print(*ans)
    
for _ in range(int(input())):
    main()