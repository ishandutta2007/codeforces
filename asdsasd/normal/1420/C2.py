import sys
input = sys.stdin.readline

def main():
    n, q = map(int, input().split())
    alst = [0, 0] + list(map(int, input().split())) + [0, 0]
    pm = [0 for _ in range(n + 4)]
    ans = 0
    for i in range(2, n + 2):
        if alst[i - 1] < alst[i] and alst[i + 1] <= alst[i]:
            pm[i] = 1
            ans += alst[i]
        elif alst[i - 1] > alst[i] and alst[i + 1] >= alst[i]:
            pm[i] = -1
            ans -= alst[i]
    print(ans)
    for _ in range(q):
        l, r = map(int, input().split())
        l += 1
        r += 1
        lr_s = set()
        for lr in [l, r]:
            for i in range(lr - 1, lr + 2):
                lr_s.add(i)
                
        for i in lr_s:
            ans -= alst[i] * pm[i]
        alst[l], alst[r] = alst[r], alst[l]
        
        for i in lr_s:
            if alst[i - 1] < alst[i] and alst[i + 1] <= alst[i]:
                pm[i] = 1
                ans += alst[i]
            elif alst[i - 1] > alst[i] and alst[i + 1] >= alst[i]:
                pm[i] = -1
                ans -= alst[i]
            else:
                pm[i] = 0
        print(ans)

for _ in range(int(input())):
    main()