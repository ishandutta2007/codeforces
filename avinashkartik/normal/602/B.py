n = int(input())
a = list(map(int,input().split()))
m = 1
st = a[0]
pv = -1
cur = 0
lastcur = 0
ct = 1
for i in range(1,n):
    #print(pv,cur)
    if(a[i] == a[cur]):
        cur = i
        ct += 1
        continue
    if(a[i] == a[pv] or pv == -1):
        ct += 1
        pv = lastcur
        cur = i
        lastcur = i
    else:
        m = max(ct,m)
        pv = lastcur
        ct = i-pv+1
        cur = i
        lastcur = i
#print(pv,cur)
print(max(m,ct))