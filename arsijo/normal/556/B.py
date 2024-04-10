n = int(input())
ar = []
a = list(map(int, input().split()))
for i in range(n):
    if i % 2 == 0:
        ar.append((n + i - a[i]) % n)
    else:
        ar.append((n - i + a[i]) % n)
ans = 'Yes'
for i in range(1, n):
    if ar[i] != ar[i - 1]:
        ans = 'No'
print(ans)