n = int(input())
s = ''

for i in range(n):
    x = input()
    if s.count('++')>0 or x.count('OO') == 0:
        s += x + '\n'
    else:
        x = x.replace('OO', '++', 1)
        s += x + '\n'
if s.count('++')>0:
    print("YES")
    print(s)
else:
    print('NO')