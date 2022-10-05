def solve(n, a):
    s = [False] * (n + 2)
    a.sort(key=lambda x: x[1] - x[0])
    for l, r in a:
        for i in range(l, r + 1):
            if not s[i]:
                print(l, r, i)
                s[i] = True
                break


for _ in range(int(input())):
    n = int(input())
    a = []
    for i in range(n):
        l, r = map(int, input().split())
        a.append((l, r))
    solve(n, a)