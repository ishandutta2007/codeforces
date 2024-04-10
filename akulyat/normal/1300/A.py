def solve():
    n = int(input())
    m = list(map(int, input().split()))
    zeroes = 0
    summ = 0
    for i in m:
        summ += i
        zeroes += (i == 0)
    ans = zeroes
    ans += (zeroes + summ == 0)
    print(ans)


t = int(input())
while (t):
    solve()
    t -= 1