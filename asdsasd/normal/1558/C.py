import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    pos = [-1] * n
    for i, a in enumerate(alst):
        a -= 1
        alst[i] -= 1
        if (a - i) % 2 == 1:
            print(-1)
            return
        pos[a] = i
    ans = []
    for i in range(n - 1, 0, -2):
        p = pos[i]
        ans.append(p + 1)
        for j in range(p // 2):
            alst[j], alst[p - j] = alst[p - j], alst[j]
            pos[alst[j]], pos[alst[p - j]] = pos[alst[p - j]], pos[alst[j]] 
        p = pos[i - 1]
        ans.append(p)
        p -= 1
        for j in range(p // 2):
            alst[j], alst[p - j] = alst[p - j], alst[j]
            pos[alst[j]], pos[alst[p - j]] = pos[alst[p - j]], pos[alst[j]] 
        ans.append(p + 3)
        p += 2
        for j in range(p // 2):
            alst[j], alst[p - j] = alst[p - j], alst[j]
            pos[alst[j]], pos[alst[p - j]] = pos[alst[p - j]], pos[alst[j]] 
        p = 2
        ans.append(3)
        for j in range(p // 2):
            alst[j], alst[p - j] = alst[p - j], alst[j]
            pos[alst[j]], pos[alst[p - j]] = pos[alst[p - j]], pos[alst[j]]
        p = i
        ans.append(p + 1)
        for j in range(p // 2):
            alst[j], alst[p - j] = alst[p - j], alst[j]
            pos[alst[j]], pos[alst[p - j]] = pos[alst[p - j]], pos[alst[j]]

    print(len(ans))
    print(*ans)
    
for _ in range(int(input())):
    main()