t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    a = []
    b = []
    g = False
    for x in s:
        if g:
            a.append(0)
            b.append(int(x))
            continue
        if x == '1':
            a.append(1)
            b.append(0)
            g = True
        else:
            a.append(int(x)//2)
            b.append(int(x)//2)
    print(''.join(map(str, a)))
    print(''.join(map(str, b)))