q = int(input())
b = [(2**i-1) for i in range(2, 26)]
a = [1 for i in range(2, 26)]
for i in range(len(b)):
    j = 2
    while j * j <= b[i]:
        if b[i] % j == 0:
            a[i] = b[i]//j
            break
        j += 1
for i in range(q):
    n = int(input())
    if n in b:
        print(a[b.index(n)])
    else:
        t = n
        x = 0
        while t > 0:
            t//=2
            x *= 2
            x += 1
        print(x)