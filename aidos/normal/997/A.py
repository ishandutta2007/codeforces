n, y, x = map(int, input().split())
a = input()
i = 0
cnt = 0
while i < n:
    while i < n and a[i] == '1':
        i+=1
    if i==n:
        break
    cnt += 1
    while i < n and a[i] == '0':
        i += 1
if cnt == 0:
    print(0)
else:
    print(min(cnt * x, (cnt-1) * y + x))