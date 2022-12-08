n=int(raw_input())
a=map(int, raw_input().split())
"""
n=10000
a=[i for i in range(10000)]
"""
if n==1:
    if a[0]==0:
        print 1,1
        print 1,1
        exit()
    else:
        print(-1)
        exit()

ct=[0 for i in range(1000000)]
for x in a:
    ct[x]+=1
i=0
while ct[i]>0:
    i+=1
ct=ct[:i]

maxd=i-1

full=[1]+[4*i for i in range(1,maxd+1)]
trunk=[full[i]-ct[i] for i in range(maxd+1)]
i=0
while i<maxd+1:
    if trunk[i]==0:
        i+=1
    elif trunk[i]<0:
        print(-1)
        exit()
    else:
        break
mindis=i

def chk(a,b,x,y,maxd):
    n1,n2=x,y
    if n1>n2:
        n1,n2=n2,n1
    ct1=[i+1 for i in range(n1)]+[n1 for i in range(n1,n2)]+[n1+n2-i-1 for i in range(n2,n1+n2)]+[0 for i in range(n1+n2,maxd+1)]
    n1,n2=x,b-y+1
    if n1>n2:
        n1,n2=n2,n1
    ct2=[i+1 for i in range(n1)]+[n1 for i in range(n1,n2)]+[n1+n2-i-1 for i in range(n2,n1+n2)]+[0 for i in range(n1+n2,maxd+1)]
    n1,n2=a-x+1,b-y+1
    if n1>n2:
        n1,n2=n2,n1
    ct3=[i+1 for i in range(n1)]+[n1 for i in range(n1,n2)]+[n1+n2-i-1 for i in range(n2,n1+n2)]+[0 for i in range(n1+n2,maxd+1)]
    n1,n2=a-x+1,y
    if n1>n2:
        n1,n2=n2,n1
    ct4=[i+1 for i in range(n1)]+[n1 for i in range(n1,n2)]+[n1+n2-i-1 for i in range(n2,n1+n2)]+[0 for i in range(n1+n2,maxd+1)]

    ct=[ct1[i]+ct2[i]+ct3[i]+ct4[i] for i in range(maxd+1)]
    for i in range(x):
        ct[i]-=1
    for i in range(y):
        ct[i]-=1
    for i in range(a-x+1):
        ct[i]-=1
    for i in range(b-y+1):
        ct[i]-=1
    ct[0]=1
    return ct
i=2*mindis-1
while i*i<=n:
    if n%i==0  and n>=i*(2*mindis-1) and i+n/i>=maxd-2+2*mindis and i+n/i<=2*maxd+2:
        a=i
        b=n/a
        x=mindis
        y=a+b-x-maxd
        if a-x+1>=mindis and y>=mindis and b-y+1>=mindis:
            if chk(a,b,x,y,maxd)==ct:
                print a,b
                print x,y
                exit()
        y=mindis
        x=a+b-y-maxd
        if a-x+1>=mindis and b-y+1>=mindis and a-x>=mindis:
            if chk(a,b,x,y,maxd)==ct:
                print a,b
                print x,y
                exit()
    i+=1
print(-1)
exit()