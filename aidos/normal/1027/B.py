n, q = map(int, input().split())
a = []
val = (n*n+1)//2
for i in range(q):
    x, y = map(int, input().split())
    if (x + y) % 2 == 0:
        if x % 2==1:
            a.append(str(((x-1)//2) * n+(y + 1)//2))
        else:
            a.append(str(((x-2)//2) * n + (n + 1)//2 + y//2))
    else:
        k = 0
        if x % 2==1:
            a.append(str(((x-1)//2) * n + y//2 + val))
        else:
            a.append(str(((x-2)//2) * n + n//2 + (y+1)//2 + val))
print('\n'.join(a))