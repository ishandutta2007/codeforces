s = input()
n = len(s)
a = [0]
for i in range(1,n):
    if i % 2 == 0:
        a = [i] + a
    else:
        a = a + [i]
b = [0] * n
for i in range(n):
    b[a[i]] = s[i]
print(''.join(b))