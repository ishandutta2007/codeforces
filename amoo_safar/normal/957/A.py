n = int(input())
a= input()
f = 0
for i in range(n-1):
    if( a[i] == a[i+1] )and(a[i]!='?'):
        f = 1
        break
if f:print('No')
else:
    o = a[0]
    for i in range(1,n-1):
        if a[i] == '?':
            if (a[i-1]!= '?')and(a[i+1]!='?')and(a[i-1]!=a[i+1]):
                o += 'X'
            else:o+=a[i]
        else:
            o+=a[i]
    o +=a[-1]
    #print(o)
    if '?' in o:print('Yes')
    else:print('No')