n = int(input())
a = list(input())[:-10]
c = a.count('8')
d = len(a) - c
for i in range(len(a)-1):
    if i % 2 == 0:
        d -= 1
    else:
        c -= 1
if c > 0:
    print('YES')
else:
    print('NO')