n=int(input())
L=list(map(int,input().split()))
out=[]
l=0
for i in L:
    if i==l+1:
        l+=1
    elif i==1:
        out.append(l)
        l=1
if l!=0:
    out.append(l)
print(len(out))
for i in out:
    print(i,end=" ")