t = int(input())
for i in range(t):
    ans = 0
    n = int(input())
    while n >= 10:
        x = n % 10
        ans += n - x
        n = n//10 + x
    print(ans + n)