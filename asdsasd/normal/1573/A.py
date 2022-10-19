for _ in range(int(input())):
    n = int(input())
    S = input()
    ans = 0
    for i, s in enumerate(S):
        s = int(s)
        if i == n - 1:
            ans += s
        elif s != 0:
            ans += s + 1
    print(ans)