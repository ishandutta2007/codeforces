T=int(input())
while T:
    n,a,bd=int(input()),sorted(list(map(int,input().split()))),[0]*1000001
    for i in range(n):
        for j in range(i+1,n):
            bd[a[j]-a[i]]=1
    i=1
    while(any(bd[i*j]for j in range(1,n))):i+=1
    print('YES\n'+' '.join(str(i*j+1)for j in range(n)))
    T-=1