n = int(input())
s = input()
a = ''
for i in s:
    if len(a) == 0 or a[-1] == 'D' or a[-1] == i:
        a = a + i
    else:
        a = a[:-1] + 'D'
print(len(a))