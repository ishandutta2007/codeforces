def f(a):
    return (str(bin(a))[2:]).count('1')

n,m,k=map(int,input().split())
a=[0]*(m+1)
a=[int(input()) for x in range(m+1)]

ans=0
i=m
for j in range(m):
    if(f(a[i]^a[j])<=k):
        ans+=1

print(ans)