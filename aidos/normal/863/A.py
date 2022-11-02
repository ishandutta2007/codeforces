s = input()

for i in range(100):
    if s == s[::-1]:
        break
    s = '0' + s
if s == s[::-1]:
    print('YES')
else:
    print('NO')