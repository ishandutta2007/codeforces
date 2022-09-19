n,m,k = map(int,input().split())
if k < n:print(k+1,1)
else:
    k-=n
    m-=1
    mo = k% (2*m)
    if mo >= m:
        mo = (2*m-1)-mo
    print(n-k//m,2+mo)