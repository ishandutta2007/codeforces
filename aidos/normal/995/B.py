n = int(input())
a=list(map(int, input().split()))
ans = 0
b = [-1] * (2*n)
x = 0
for i in range(2*n):
    for j in range(i+1, 2 * n):
        if a[i] == a[j]:
            b[i] = x
            b[j] = x
            x += 1

for i in range(2 * n):
    for j in range(1, 2 * n):
        if b[j] < b[j-1]:
            b[j-1], b[j] = b[j], b[j-1]
            ans += 1
print(ans)