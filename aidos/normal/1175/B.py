l = int(input())
a = [0] * (l+1)
b = [1] * (l+1)
st = 0
en = 1
cur = 0
for i in range(l):
    x = input()
    if x == 'add':
        a[en-1] += 1
    elif x[0] == 'f':
        d = x.split()
        v = int(d[1])
        a[en] = 0
        b[en] = v
        en += 1
    else:
        en -= 1
        a[en-1] += a[en] * b[en]
        if a[en-1] >= 2 ** 32:
            cur = 1
            break
if cur == 1 or a[0] >= 2 ** 32:
    print('OVERFLOW!!!')
else:
    print(a[0])