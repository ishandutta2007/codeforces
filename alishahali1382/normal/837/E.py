a,b=map(int,input().split())
A=[]
for i in range(2,int(a**0.5)+1):
    while a%i==0:
        a//=i
        A.append(i)
if a!=1:
    A.append(a)

#print(A)
out=0
while b>0:
    n=len(A)
    x=-1
    for i in range(n):
        if x==-1 or b%A[i]<b%A[x]:
            x=i
        
    if n==0:
        out+=b
        b=0
        break

    A[x],A[n-1]=A[n-1],A[x]
    out+=b%A[n-1]
    b//=A.pop()
print(out)