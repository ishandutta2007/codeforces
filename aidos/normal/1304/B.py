n, m = map(int, input().split())
u = []
a = []
for i in range(n):
    a.append(input())
    u.append(False)
s = ''
t = ''

for i in range(n):
    for j in range(n):
        if u[i] == False and u[j] == False and a[i] == a[j][::-1] and i != j:
            u[i] = True
            u[j] = True
            s = s + a[i]
            t = a[j] + t


for i in range(n):
    if u[i] == False and a[i] == a[i][::-1]:
        s = s + a[i]
        break
s = s + t
print(len(s))
print(s)