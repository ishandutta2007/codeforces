n = input()
ans = 0
for i in range(1,n+1):
    for j in range(1,i+1):
        if j >= i^j > i-j and i^j<=n: ans += 1
print(ans)