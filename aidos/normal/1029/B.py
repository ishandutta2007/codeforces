n = int(input())
a = list(map(int, input().split()))
ans = 0
i = 0
j = 0
while i < n:
    if i >= j:
        j = i + 1
    while j < n and a[j] <= a[j-1] * 2:
        j += 1
    ans = max(ans, j - i)
    i += 1
print(ans)