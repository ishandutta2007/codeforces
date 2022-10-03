from sys import stdout,exit
m,n=map(int,input().split())
p=[-1]*30

for i in range(n):
    print(m)
    stdout.flush()
    tmp=int(input())
    if tmp==0:
        exit()
    elif tmp==-1:
        p[i]=1

l=1
r=m+1
for i in range(60-n):
    if r-l==1:
        print(l)
        stdout.flush()
        input()
        exit()
    
    mid=(l+r)//2
    print(mid)
    stdout.flush()
    tmp=int(input())*p[i%n]
    if tmp==0:
        exit()
    elif tmp==-1:
        r=mid
        continue
    l=mid+1