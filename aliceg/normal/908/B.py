n, m = map(int, input().split())
a = [0] * n
for i in range(n):
    a[i] = input()
    for j in range(m):
        if a[i][j] == 'S':
            x1, y1 = i, j
s = input()
dirr = ['0123', '0132', '0213', '0231', '0312', '0321', '1023', '1032', '1203', '1230', '1302', '1320', '2103', '2130', '2013', '2031', '2310', '2301', '3120', '3102', '3210', '3201', '3012', '3021']
ans = 0
for d in dirr:
    x, y = x1, y1
    for i in s:
        i = int(i)
        if d[i] == '0' and (x - 1 < 0 or a[x - 1][y] == '#'):
            break
        elif d[i] == '1' and (y - 1 < 0 or a[x][y - 1] == '#'):
            break
        elif d[i] == '2' and (x + 1 >= n or a[x + 1][y] == '#'):
            break
        elif d[i] == '3' and (y + 1 >= m or a[x][y + 1] == '#'):
            break
        elif d[i] == '0':
            x -= 1
        elif d[i] == '1':
            y -= 1
        elif d[i] == '2':
            x += 1
        elif d[i] == '3':
            y += 1
        if a[x][y] == 'E':
            break
    if a[x][y] == 'E':
        ans += 1
print(ans)