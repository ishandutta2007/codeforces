n=input()
count=len(n)
rad=int(int(n)**0.5)+1

def check(s):
    if s=="":
        return False
    if s[0]=="0":
        return False
    z=int(s)
    return int(z**0.5)**2==z

sub=[[]]
for i in range(count):
    X=[]
    for j in sub:
        X.append(j+[i])
    sub+=X

out=10
for i in sub:
    A=[1]*(count+5)
    for j in i:
        A[j]=0
    s=""
    for j in range(count):
        if A[j]==1:
            s+=n[j]
    if check(s):
        out=min(out,len(i))
if out==10:
    print(-1)
else:
    print(out)