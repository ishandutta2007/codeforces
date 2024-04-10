def f(x,base):
    out=0
    while x%base==0:
        x//=base
        out+=1
    return out
n=int(input())
L=list(map(lambda i:[-f(int(i),3),int(i)],input().split()))
L.sort()
for i,j in L:
    print(j,end=" ")
print()