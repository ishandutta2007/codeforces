n=int(input())
out=n
L=list(map(int,input().split()))
X=dict()

def f(x):
    try:
        return X[x]
    except:
        return -1

for i in range(n):
    x=L[i];
    while (f(x)!=-1):
        L[X[x]]=-1
        out-=1
        X[x]=-1
        L[i]*=2
        x=L[i]
    X[x]=i
print(out)
for i in range(n):
    if (L[i]!=-1):
        print(L[i],end=" ")
print()