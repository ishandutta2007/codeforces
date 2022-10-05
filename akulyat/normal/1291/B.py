def solve():
    n = int(input())
    m = list(map(int, input().split()))
    ans = True
    for i in range(n):
        min_val = min(i, n - 1 - i)
        if (m[i] < min_val):
            ans = False
    if (n % 2 == 0):
        if (m[n // 2] == m[n // 2 - 1] and m[n // 2] == n // 2 - 1):
            ans = False
    if (ans):
        print("Yes")
    else:
        print("No")


t = int(input())
while (t):
    solve()
    t -= 1