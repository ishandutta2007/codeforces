a = sorted(map(int, input().split()))
s = sum(a)
if s % 2 != 0:
    print('NO')
    exit(0)
s //= 2
for j in range(1, 6):
    for k in range(j+1, 6):
        if a[0] + a[j] + a[k]==s:
            print('YES')
            exit(0)
print('NO')