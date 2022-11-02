n = int(input())
a = list(map(int, input().split()))
x = max(a)
i = 0
ans = 0
while i < n:
    j = i
    while i < n and a[i] == a[j]:
        i += 1
    if a[j] == x:
        ans = max(ans, i - j)
print(ans)