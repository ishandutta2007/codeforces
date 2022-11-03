a = [0] * 9
j = 0
for i in range(11):
    if i == 3 or i == 7:
        w = input()
        continue
    a[j] = list(''.join(input().split()))
    j += 1

x, y = map(int, input().split())
x -= 1
y -= 1
x %= 3
y %= 3

if x == 1:
    x = 3
elif x == 2:
    x = 6

if y == 1:
    y = 3
elif y == 2:
    y = 6

flag = True
for i in range(x, x + 3):
    for j in range(y, y + 3):
        if a[i][j] == '.':
            flag = False
            a[i][j] = '!'

for i in range(9):
    if i % 3 == 0 and i != 0:
        print('')
    for j in range(9):
        if j % 3 == 0 and j != 0:
            print(' ', end='')        
        if flag and a[i][j] == '.':
            print('!', end='')
        else:
            print(a[i][j], end='')
    print('')