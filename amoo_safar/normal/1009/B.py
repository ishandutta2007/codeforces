a = input()+'2'
f = a.index('2')
b = a[f:]
o = ''
for i in b:
    if i !='1':
        o+=i
a = a[:f]
print(a.count('0')*'0'+a.count('1')*'1'+b.count('1')*'1'+o[:-1])