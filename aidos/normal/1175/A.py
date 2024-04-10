t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    ans = 0
    while n > 0:
        if n % k == 0:
            n//=k
            ans += 1
        else:
            ans += n % k
            n -= n % k
    print(ans)