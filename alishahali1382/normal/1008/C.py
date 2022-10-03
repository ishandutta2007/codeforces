n=int(input())
A=sorted(list(map(int,input().split())))
L=[[A[0],1]]
for i in range(1,n):
    if A[i]==A[i-1]:
        L[-1][1]+=1
    else:
        L.append([A[i],1])

ans=0
s=0
for i,j in L:
    t=min(j,s)
    ans+=t
    s-=t
    s+=j
print(ans)