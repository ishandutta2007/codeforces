n = int(input())
a = []
for i in range(n):
    l, r = map(int, input().split())
    a.append((r, l))
a.sort()
L = -1
ans = 0
for x in a:
    if x[1] > L:
        L = x[0]
        ans += 1
print(ans)