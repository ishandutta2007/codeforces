n = int(input())
a = input()
b = dict()
for i in range(1, n):
    s = a[i-1] + a[i]
    c = b.get(s, 0)
    b[s] = c + 1
mx = 0
ans = ''
for key, value in b.items():
    if value > mx:
        mx = value
        ans = key
print(ans)