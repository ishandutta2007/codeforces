def solve():
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    j = 0
    ans = 0
    for i in range(n):
        if (i - j + 1) * a[i] >= x:
            j = i + 1
            ans += 1
    print(ans)

t = int(input())

for test in range(t):
    solve()