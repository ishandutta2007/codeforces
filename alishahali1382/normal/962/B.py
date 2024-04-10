n,a,b=map(int,input().split())
inp=input().split("*")
L=[]
for i in inp:
    L.append(len(i))

out=0
for i in L:
    c1=i//2
    c2=i-c1
    if b<a:
        a,b=b,a
    if a<c1:
        out+=a
        a=0
    else:
        a-=c1
        out+=c1
    if b<c2:
        out+=b
        b=0
    else:
        b-=c2
        out+=c2
print(out)