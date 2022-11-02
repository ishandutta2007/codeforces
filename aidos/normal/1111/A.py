a = ['a', 'e', 'i', 'o', 'u']
s = input()
t = input()
ss = []
tt = []
for i in s:
    if i in a:
        ss.append('a')
    else:
        ss.append('b')

for i in t:
    if i in a:
        tt.append('a')
    else:
        tt.append('b')
if ss == tt:
    print('Yes')
else:
    print('No')