n, k = map(int, input().split())
ans = -1
for i in range(1, k):
    if n % i == 0:
        c = (n//i) * k + i
        if ans == -1:
            ans = c
        else:
            ans = min(ans, c)
print(ans)