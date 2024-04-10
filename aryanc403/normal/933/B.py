def solve(n,p,k):
    # print(n,p,k)
    P=p
    cf=1
    a=[0]*n
    for i in range(n):
        if i&1:
            p+=cf*(k-1)
            a[i]-=k-1
        cf*=k
    # print(p)    
    for i in range(n):
        a[i]+=p%k
        p//=k
    # print(n,a)
    if p:
        return
    for i in range(n):
        if i&1:
            a[i]*=-1
    cf=1
    p=P
    for i in range(n):
        if a[i]<0 or a[i]>=k:
            return
        if i&1:
            p+=a[i]*cf
        else:
            p-=a[i]*cf
        cf*=k
    if p:
        return
    print(len(a))
    print(*a)
    exit(0)

p,k=map(int,input().split())
for i in range(100):
    if k**i>1<<100:
        break
    solve(i,p,k)
print(-1)