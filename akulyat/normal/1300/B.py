def solve():
    n = int(input())
    m = list(map(int, input().split()))
    m.sort()
    print(m[n] - m[n - 1])


t = int(input())
while (t):
    solve()
    t -= 1