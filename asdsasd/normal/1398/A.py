for _ in range(int(input())):
    n = int(input())
    alst = list(map(int, input().split()))
    if alst[0] + alst[1] > alst[-1]:
        print(-1)
    else:
        print(1, 2, n)