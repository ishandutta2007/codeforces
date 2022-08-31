n,m,k = map(int,input().split())
l = list(map(int,input().split()))
ct = 0
i = 0
while(i < m):
    cur = i
    curv = (l[i]-1-cur)//k
    while(i<m and (l[i]-1-cur)//k == curv):
        i += 1
    ct += 1
print(ct)