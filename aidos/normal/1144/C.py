n = int(input())
a = sorted(map(int, input().split()))
b = a[::2]
c = a[1::2]
if len(set(b)) + len(set(c)) == n:
    print('YES')
    print(len(b))
    print(' '.join(map(str, b)))
    print(len(c))
    print(' '.join(map(str, c[::-1])))
else:
    print('NO')