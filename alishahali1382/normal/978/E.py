n,w=map(int,input().split())
L=list(map(int,input().split()))
maxx=0
minn=0
x=0
for i in L:
    x+=i
    maxx=max(maxx,x)
    minn=min(minn,x)
    
print(max(0,(w+minn)-maxx+1))