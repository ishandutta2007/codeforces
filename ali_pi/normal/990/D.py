n, a, b = map(int,raw_input().split())
if min(a, b) > 1 or 1 < n < 4 and max(a, b) == 1:
    print('NO')
    exit()
print('YES')
f = int(a == 1)
g = [a, b][f]
r = [[f] * n for i in range(n)]
for i in range(n):
    r[i][i] = 0
for i in range(n - g):
    r[i][i + 1] ^= 1
    r[i + 1][i] ^= 1
print('\n'.join(map(lambda x: ''.join(map(str, x)), r)))