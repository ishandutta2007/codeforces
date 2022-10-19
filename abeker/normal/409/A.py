def get(c):
    return "8[(".index(c)

def win(d, e):
    return (get(d) + 1) % 3 == get(e)

a = input()
b = input()
x = 0
y = 0
for i in range(0, len(a), 2):
    x += win(a[i], b[i])
    y += win(b[i], a[i])

if x > y:
    print('TEAM 1 WINS')
elif x < y:
    print('TEAM 2 WINS')
else:
    print('TIE')