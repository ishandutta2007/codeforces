n, p = map(int, input().split())
a = input()
b = list(a)
for i in range(p):
    j = i
    c = a[j]
    if j + p < n and a[j] == '.':
        c = a[j + p]
    if c == '.':
        c = '0'
    cnt = 0
    for j in range(i, n, p):
        if a[j] == '.':
            if cnt % 2 == 0:
                if c == '0':
                    b[j] = '1'
                else:
                    b[j] = '0'
            else:
                b[j] = c
            cnt += 1
ok = 0
for i in range(p, n):
    if b[i] != b[i-p]:
        ok = 1
if ok == 1:
    print(''.join(b))
else:
    print("No")