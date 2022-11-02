n = int(input())
a = ['a', 'a']

for i in range(2, n):
    y = a[-2]
    if y == 'a':
        y = 'b'
    else:
        y = 'a'
    a.append(y)
print(''.join(a[:n]))