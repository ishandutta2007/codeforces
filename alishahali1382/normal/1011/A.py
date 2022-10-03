orda=ord("a")-1
n,k=list(map(int,input().split()))
L=sorted(list(set(list(map(lambda i:ord(i)-orda,list(input()))))))
n=len(L)
ans=L[0]
x=1
l=L[0]
for i in range(1,n):
    if k==x:
        break
    if l<=L[i]-2:
        ans+=L[i]
        x+=1
        l=L[i]

if k!=x:
    print(-1)
else:
    print(ans)