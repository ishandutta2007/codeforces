s = input()
a = []
cnt = 0
for x in s:
    if x == '1':
        cnt += 1
    else:
        a.append(x)
i = 0
while i < len(a) and a[i] == '0':
    i += 1
print('0'*i + '1' * cnt + ''.join(a[i:]))