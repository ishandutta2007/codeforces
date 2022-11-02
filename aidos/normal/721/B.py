n, k = map(int, input().split())
a = []
for i in range(n):
    a.append(input())
s = input()
ans = 0
b = []
for i in range(n):
    t = 1
    if a[i] == s:
        t = 0
    b.append([len(a[i]), t])
b = sorted(b)
cnt = 0
x = 0
for g in b:
    cnt += 1
    x += 1
    if g[1] == 0:
        break
    if x % k == 0:
        cnt += 5
print(cnt, end = ' ')

b = []
for i in range(n):
    t = 0
    if a[i] == s:
        t = 1
    b.append([len(a[i]), t])
b = sorted(b)
cnt = 0
x = 0
for g in b:
    cnt += 1
    x += 1
    if g[1] == 1:
        break
    if x % k == 0:
        cnt += 5
print(cnt)