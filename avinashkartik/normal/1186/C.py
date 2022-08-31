a = list(input())
b = list(input())
ctb = b.count('1')
n = len(b)
cta = a[:n].count('1')
m = len(a)
s = 0
for i in range(n-1,m):
    #print(i,i-n+1)
    if (cta + ctb)%2 == 0:
        s += 1
    if(i != m-1):
        if(a[i+1] == '1'):
            cta += 1
        if(a[i-n+1] == '1'):
            cta -= 1
print(s)