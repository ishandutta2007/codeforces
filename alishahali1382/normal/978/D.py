n=int(input())
a=list(map(int,input().split()))
inf=100001
def f(x,y):
    b=a.copy()
    b[0]+=x
    b[1]+=y
    step=b[1]-b[0]
    ans=abs(x)+abs(y)
    for i in range(2,n):
        f=b[i-1]+step
        ch=abs(f-b[i])
        if ch>1:
            return inf
        ans+=ch
        b[i]=f
    return ans
if n<3:
    print(0)
else:
    ans=inf
    for i in -1,0,1:
        for j in -1,0,1:
            z=f(i,j)
            ans=min(ans,z)
    if ans==inf:
        print(-1)
    else:
        print(ans)