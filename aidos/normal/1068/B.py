n = int(input())
t = 1
ans = 0
while t * t <= n:
    if n % t == 0:
        ans += 1
        if t * t < n:
            ans += 1
    t += 1
print(ans)