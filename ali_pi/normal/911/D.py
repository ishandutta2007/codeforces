import sys
f=sys.stdin
n=int(f.readline())
a=list(map(int,f.readline().split()))
s=0
for i in range(n):
    for j in range(i):
        s^=a[j]>a[i]
q=int(f.readline())
for i in range(q):
    l,r=map(int,f.readline().split())
    s^=(r-l+1)*(r-l)//2%2
    print(['even','odd'][s])