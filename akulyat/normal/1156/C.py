n, d=map(int, input().split())
m=list(map(int, input().split()))
m.sort()
l=0
r=n//2+1
while l+1<r:
    mi=(l+r)//2
    norm=True
    for i in range(mi):
        if (m[i]+d>m[n-mi+i]):
            norm=False
    if norm:
        l=mi
    else:
        r=mi
print(l)