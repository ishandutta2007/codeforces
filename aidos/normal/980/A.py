s = input()
x = s.count('o')
y = s.count('-')
if x <= 1 or y % x == 0:
    print('YES')
else:
    print('NO')