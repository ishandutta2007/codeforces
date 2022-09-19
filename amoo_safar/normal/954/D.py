n,m,s,e = map(int,input().split())
s -= 1
e -= 1
md = []
g = []
for i in range(n):
    md.append([-1,-1])
    g.append([])
for i in range(m):
    u,v = map(int,input().split())
    g[u-1].append(v-1)
    g[v-1].append(u-1)

#bfs
md[s][0] = 0
d = 0
st = [s]
c = 1
#print('s')
while c < n:
    #print(c)
    d += 1
    st2 = []
    for node in st:
        for p in g[node]:
            if md[p][0] == -1:
                st2.append(p)
                md[p][0] = d

    c+=len(st2)
    st = st2[:]

#bfs
md[e][1] = 0
d = 0
st = [e]
c = 1
#print('s')
while c < n:
    #print(c)
    d += 1
    st2 = []
    for node in st:
        for p in g[node]:
            if md[p][1] == -1:
                st2.append(p)
                md[p][1] = d

    c+=len(st2)
    st = st2[:]
#print(md)
dis = md[e][0]
t = 0
for i in range(n):
    for j in range(i):
        if j in g[i]:continue
        if dis <= min(md[i][0] + md[j][1],md[j][0] + md[i][1])+1:
            t += 1
print(t)