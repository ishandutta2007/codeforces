s=list(map(int,input()))
ans=0
L=[[]]
for i in s:
    r=i%3
    if r!=0:
        L[-1].append(r)
    else:
        L.append([])
        ans+=1
n=len(L)
for A in L:
    m=len(A)
    k=0
    x=0
    f=[True]*m
    for i in range(m):
        x+=A[i]
        if x%3==0 or (i!=0 and A[i-1]+A[i]==3 and f[i-1]):
            x=0
            f[i]=False
            k+=1
    kk=0
    '''
    x=0
    for i in range(1,m):
        x+=A[i]
        if x%3==0:
            x=0
            kk+=1
    '''
    ans+=max(k,kk)
    
print(ans)