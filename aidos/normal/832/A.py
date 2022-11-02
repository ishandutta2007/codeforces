n, k = map(int, input().split())

n//=k
if n % 2 == 1:
    print('YES')
else:
    print('NO')