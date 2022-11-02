n = int(input())
a = list(map(int, input().split()))
l = [-1] * 100200
r = [-1] * 100200
b = [0] * 100200
for i in range(n):
    x = a[i]
    if l[x] == -1:
        l[x] = i
    r[x] = i

for i in range(100100):
    if l[i] != -1:
        b[l[i]] += 1

for i in range(1, 100100):
    b[i] += b[i-1]

ans = 0
    

for i in range(1, 100100):
    if r[i] != -1:
        ans += b[r[i]-1]
print(ans)