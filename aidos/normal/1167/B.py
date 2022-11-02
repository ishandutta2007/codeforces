def get(x, y, a):
    for i in a:
        for j in a:
            for k in a:
                if i * j == x and j * k == y and i != k and j != k and i != j:
                    return [i, j, k]
    return [1, 1, 1]

a = [4 , 8, 15, 16, 23, 42]
print('? 1 2')
x = int(input())
print('? 2 3')
y = int(input())
h = get(x, y, a)
print('? 4 5')
x = int(input())
print('? 5 6')
y = int(input())
h.extend(get(x, y, a))
print('!', ' '.join(map(str, h)))