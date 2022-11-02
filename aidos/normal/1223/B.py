t = int(input())
for _ in range(t):
    s = set(input())
    t = set(input())
    if len(s.intersection(t)) > 0:
        print('YES')
    else:
        print('NO')