s = 'Bulbasaur'
a = input()
b = dict()
for i in a:
    b[i] = b.get(i, 0) + 1
cnt = 0
while True:
    x = 10
    for i in s:
        d = b.get(i, 0)
        if d == 0:
            x = 0
        else:
            b[i] = d - 1
    if x==0:
        break
    cnt += 1
print(cnt)