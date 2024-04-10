n = int(input())

ans = 0
while n > 0:
    ans += n % 2
    n//=2
print(ans)