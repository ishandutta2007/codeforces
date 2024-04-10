n, k = list(map(int, input().split()))
p = list(map(int, input().split()))
c = list(map(int, input().split()))
arr = [[p[i], i] for i in range(n)]
arr.sort()
z = []
ans = [0 for i in range(n)]
for i in range(n):
    s = 0
    for el in z:
        s += el
    ans[arr[i][1]] = s + c[arr[i][1]]
    z.append(c[arr[i][1]])
    z.sort()
    if len(z) > k:
        z = z[1:]
for el in ans:
    print(el, end=" ")