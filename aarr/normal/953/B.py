n=int(input())
a=input()
a=a.split()
for i in range(n):
    a[i]=int(a[i])
a.sort()
l=[]
for i in range(n-1):
    l.append(a[i+1]-a[i])          
def bmm(a,b):
    if b==0:
        return a
    return bmm(b,a%b)
x=l[0]
for i in range(n-1):
    x=bmm(l[i],x)
print((a[-1]-a[0])//x-n+1)