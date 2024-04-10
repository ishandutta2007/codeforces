n,m,s,t = map(int, raw_input().split())
a=[0]*(n+1)
b=list(a)
g= [[] for i in range(n+1)]
for i in range(m):
    u,v = map(int, raw_input().split())
    g[u]+=[v]
    g[v]+=[u]

def bfs(x, a):
    q=[x]
    while q:
        c=q.pop()
        for y in g[c]:
            if not a[y]:
                a[y] = a[c]+1
                q.insert(0,y)
    a[x]=0
bfs(s,a)
bfs(t,b)
r=0
for i in range(1,n+1):
    for j in range(i + 1, n + 1):
        if not i in g[j] :
            if min(a[i]+b[j]+1, a[j]+b[i]+1) >= a[t]:
                r+=1
print r