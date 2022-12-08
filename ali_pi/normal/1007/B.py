N=100001
fac=[0 for i in range(N)]
for i in range(1,N):
    for j in range(i,N,i):
        fac[j]+=1
def gcd(a,b):
        if a<b:
            a,b=b,a
        while b>0:
            a,b=b,a%b
        return a
def ctt(A,B,C):
    la=fac[A]
    lb=fac[B]
    lc=fac[C]
    ab=gcd(A,B)
    ac=gcd(A,C)
    bc=gcd(B,C)
    abc=gcd(ab,C)
    dupabc=fac[abc]
    dupac=fac[ac]-dupabc
    dupbc=fac[bc]-dupabc
    dupab=fac[ab]-dupabc
    lax=la-dupabc-dupab-dupac
    lbx=lb-dupabc-dupab-dupbc
    lcx=lc-dupabc-dupac-dupbc
    ctx=lax*lbx*lcx
    ctx+=lax*lbx*(lc-lcx)
    ctx+=lax*lcx*(lb-lbx)
    ctx+=lcx*lbx*(la-lax)
    ctx+=lax*((lb-lbx)*(lc-lcx)-(dupabc+dupbc)*(dupabc+dupbc-1)/2)
    ctx+=lbx*((la-lax)*(lc-lcx)-(dupabc+dupac)*(dupabc+dupac-1)/2)
    ctx+=lcx*((la-lax)*(lb-lbx)-(dupabc+dupab)*(dupabc+dupab-1)/2)
    ctx+=dupab*dupac*dupbc
    ctx+=dupab*dupac*(dupab+dupac+2)/2
    ctx+=dupab*dupbc*(dupab+dupbc+2)/2
    ctx+=dupbc*dupac*(dupbc+dupac+2)/2
    ctx+=dupabc*(dupab*dupac+dupab*dupbc+dupbc*dupac)
    ctx+=dupabc*(dupab*(dupab+1)+(dupbc+1)*dupbc+(dupac+1)*dupac)/2
    ctx+=(dupabc+1)*dupabc*(dupab+dupac+dupbc)/2
    ctx+=(dupabc*dupabc+dupabc*(dupabc-1)*(dupabc-2)/6)
    return int(ctx)
n=int(input())
for _ in range(n):
    a,b,c = map(int,input().split())
    print(ctt(a,b,c))
exit()