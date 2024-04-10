a = input()
n = len(a)
z = [0] * n
l = 0
r = 0
for i in range(1, n):
    if i <= r:
        z[i] = min(r-i, z[i-l])
    while i + z[i] < n and a[z[i]] == a[i + z[i]]:
        z[i] += 1
    if i + z[i] - 1 >= r:
        r = i + z[i] - 1
        l = i

mx = 0
ans = 0
for i in range(n):
    if z[i] == n - i and mx >= z[i]:
        ans = z[i]
        break
    mx = max(z[i], mx)
if ans == 0:
    print('Just a legend')
else:
    print(a[:ans])