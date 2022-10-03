n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
ps=[0]*(n+1)
for i in range(n):
    ps[i+1]=ps[i]+a[i]

def bs(l,r,key):
    if r-l<2:
        return l
    mid=(l+r)//2
    if ps[mid]>=key:
        return bs(l,mid,key)
    return bs(mid,r,key)

for i in range(m):
    key=b[i]
    x=bs(0,n,key)
    print(x+1,key-ps[x])