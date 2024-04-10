for _ in range(int(input())):
    n = int(input())
    alst = list(map(int, input().split()))
    ans = []
    for i in range(n // 2):
        ans.append(alst[2 * i + 1])
        ans.append(-alst[2 * i])
    print(*ans)