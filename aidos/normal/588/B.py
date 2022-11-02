n = int(input())
ans = 1
i = 2
while i * i <= n:
    if n % i == 0:
        while n % i == 0:
            n //= i
        ans *= i
    i += 1
if n > 1:
    ans *= n
print(ans)