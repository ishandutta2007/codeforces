n, m, k = map(int, input().split())
a = list(map(int,input().split()))
b = []
for i in range(n):
    b.append([-a[i], i])

b = sorted(b)
u = [0] * n
ans=0
for i in range(k*m):
    u[b[i][1]] = 1
    ans -= b[i][0]
c = 0
print(ans)
for i in range(n):
    c += u[i]
    if c == m and k > 1:
        print(i+1)
        c = 0
        k -= 1