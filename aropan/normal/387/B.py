n, m = map(int, raw_input().split())
a = sorted(map(int, raw_input().split()))
b = sorted(map(int, raw_input().split()))
j = 0
ans = 0
for i in range(n):
    while j < m and a[i] > b[j]:
        j += 1
    if j == m:
        ans = n - i
        break
    j += 1
print ans