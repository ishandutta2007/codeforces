n,k=map(int,input().split())
L=list(map(int,input().split()))
T=list(map(int,input().split()))
out=0
for i in range(n):
    if T[i]==1:
        out+=L[i]
        L[i]=0

ps=[0]*(n+1)
for i in range(1,n+1):
    ps[i]=ps[i-1]+L[i-1]
x=0
for i in range(n-k+1):
    x=max(x,ps[i+k]-ps[i])
print(x+out)