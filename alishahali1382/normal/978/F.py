n,k=map(int,input().split())
r=list(map(int,input().split()))
h=sorted(r)
dic=dict()

dic[h[0]]=0
for i in range(1,n):
    if h[i-1]!=h[i]:
        dic[h[i]]=i

out=[dic[r[i]] for i in range(n)]

for i in range(k):
    a,b=map(lambda i:int(i)-1,input().split())
    if r[a]>r[b]:
        out[a]-=1
    elif r[a]<r[b]:
        out[b]-=1

for i in out:
    print(i,end=" ")