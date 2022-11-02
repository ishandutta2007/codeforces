n = int(input())
a = []
for i in range(n):
    s = input()
    if s in a:
        print('YES')
    else:
        print('NO')
        a.append(s)