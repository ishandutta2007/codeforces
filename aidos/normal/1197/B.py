n = int(input())
a = list(map(int, input().split()))
i = a.index(n)
l = i - 1
r = i + 1
ans = 'YES'
for i in range(1, n):
    if l >= 0 and a[l] == n-i:
        l -= 1
    elif r < n and a[r] == n-i:
        r += 1
    else:
        ans = 'NO'
print(ans)