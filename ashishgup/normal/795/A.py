n,c1,c2=map(int,raw_input().split())
s=raw_input()
a=0
c=0

for i in range(0,n):
    if s[i]=='1' :
        a=a+1
    else :
        c=c+1
ans=10000000000000000000000000000
cst=0
for i in range(1,a+1):
    f=(c+a-i)/i
    g=(c+a-i)%i
    cst=g*(c1+c2*(f+1)*(f+1))+(i-g)*(c1+c2*(f)*(f))
    ans=min(ans,cst)
print ans