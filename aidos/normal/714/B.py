n = int(input())
s = sorted(map(int, input().split()))
d = sorted(set(s))
if len(d) <= 2:
    print('YES')
    exit(0)
if len(d) > 3:
    print('NO')
    exit(0)
if d[2] - d[1] == d[1] - d[0]:
    print('YES')
else:
    print('NO')