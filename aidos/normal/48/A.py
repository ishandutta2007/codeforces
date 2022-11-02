def win(x, y, z):
    if y != z:
        return False
    if x == 'rock':
        return y == 'scissors'
    if x == 'scissors':
        return y == 'paper'
    return y == 'rock'

a = []
b = 'FMS'
for i in range(3):
    a.append(input())

for i in range(3):
    if win(a[i], a[(i+1) % 3], a[(i+2) % 3]):
        print(b[i])
        break
else:
    print('?')