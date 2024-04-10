def get():
    N, B = map(int, input().split())
    res = 0
    for i in input().split():
        res = B * res + int(i)
    return res

x = get()
y = get()
if x < y:
    print('<')
elif x > y:
    print('>')
else:
    print('=')