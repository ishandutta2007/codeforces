x, y = map(int, input().split())

if x == y:
    print('=')
elif x == 1:
    print('<')
elif y == 1:
    print('>')
elif max(x, y) <= 20:
    a = x**y
    b = y ** x
    if a < b:
        print('<')
    elif a == b:
        print('=')
    else:
        print('>')
elif x < y:
    print('>')
else:
    print('<')