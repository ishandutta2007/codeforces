n = int(input())
ans = 0
if n % 2 == 1:
    i = 2
    cnt = -1
    while i * i <= n:
        if n % i == 0:
            cnt = i
            break
        i += 1
    if cnt == -1:
        cnt = n
    n -= cnt
    ans += 1
print(ans + n//2)