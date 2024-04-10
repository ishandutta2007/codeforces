n,k=map(int,input().split())
L=list(map(int,input().split()))
res=0
while n!=0 and L[0]<=k:
    L.pop(0)
    res+=1
    n-=1
while n!=0 and L[n-1]<=k:
    L.pop()
    res+=1
    n-=1
print(res)