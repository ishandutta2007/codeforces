def rev(k):
    return '0' if k =='1' else '1'
n,p=map(int,input().split())
a= input()
b = list(a)
f = False
for i  in range(n-p):
    c = a[i]
    d=a[i+p]
    #print(c,d)
    if '.' in [c,d]:
        if c == '.' and d!='.':
            b[i] = rev(d)
        elif c != '.' and d=='.':
            b[i+p] = rev(c)
        else:
            b[i]='1'
            b[i+p] = '0'
        f = True
    elif d!=c:f= True
if f:
    #b.replace('.','1')
    for i in b:print(i if i!='.' else '0',end='')
    print()
else:print('No')