n = int(input())
a = [int(input()) for i in range(n)]
ans = 0
for i in range(n):
    g = 1
    q = a[i]
    while q != -1:
        g += 1
        q = a[q - 1]
    ans = max(ans, g)
print(ans)