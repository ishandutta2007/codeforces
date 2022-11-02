n = int(input())
a = []
for i in range(n):
    a.append(input())
a = sorted(a)
ans = 0
for i in range(n):
    for j in range(i+1, n):
        if i % 2 == j % 2 and a[i][0] == a[j][0]:
            ans += 1
print(ans)