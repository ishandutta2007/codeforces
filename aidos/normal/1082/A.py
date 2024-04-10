t = int(input())
for i in range(t):
    n, x, y, d = map(int, input().split())
    if x % d == y % d:
        print(abs(x-y)//d)
    elif y % d==1 % d or y % d == n % d:
        ans = 10**12
        if y % d == 1 % d:
            ans = min(ans, (x-1 + d-1)//d + (y-1)//d)
        if y % d == n % d:
            ans = min(ans, (n-x+d-1)//d+(n-y)//d)
        print(ans)
    else:
        print(-1)