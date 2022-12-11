n,m = map(int,raw_input().split())

row = [0 for x in range(n+1)]
col = [0 for x in range(n+1)]
rnum = n
cnum = n

out = []
for i in range(m):
    x,y = map(int,raw_input().split())
    if not row[x]:
        rnum -= 1
    if not col[y]:
        cnum -= 1
    row[x] = 1
    col[y] = 1
    out.append(rnum*cnum)
print " ".join([str(x) for x in out])

''' 
3 3
2 2
2 3
1 3
'''