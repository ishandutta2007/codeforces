n,m=map(int,input().split())
par=[-1]*n

def find(x):
    if par[x]!=-1:
        x=find(par[x])
        
    return x

def union(x,y):
    a=find(x)
    b=find(y)
    b,a=sorted([a,b])
    if a==b:
        return
    par[a]=b

deg=[0]*n

for i in range(m):
    u,v=map(int,input().split())
    deg[u-1]+=1
    deg[v-1]+=1
    union(u-1,v-1)

R=dict()
out=0
for i in range(n):
    if par[i]==-1:
        R[i]=[]
for i in range(n):
    a=find(i)
    R[a].append(i)
    
for i in R:
    if len(R[i])>2:
        x=1
        for j in R[i]:
            if deg[j]!=2:
                x=0
                break
        if x==1:
            out+=1
print(out)