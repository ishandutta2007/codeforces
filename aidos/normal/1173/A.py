a, b, c = map(int, input().split())
x = a-b+c
y = a-b-c
d = '0'
e = '0'
if x > 0:
    d = '+'
if x < 0:
    d = '-'
if y > 0:
    e = '+'
if y < 0:
    e = '-'
if d == e:
    print(d)
else:
    print('?')