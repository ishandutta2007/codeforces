n, m = map(int, input().split())
a = map(int, input().split())
b = [0]
s = 0
for i, x in enumerate(a):
    s += x
    b.append(s)

q = list(map(int, input().split()))
c = []
ans = []
for i in range(m):
    c.append([q[i], i])
    ans.append([0, 0])
c = sorted(c)
j = 0
for i in range(m):
    while b[j] < c[i][0]:
        j += 1
    ans[c[i][1]] = [j, c[i][0] - b[j-1]]
for i in range(m):
    print(ans[i][0], ans[i][1])