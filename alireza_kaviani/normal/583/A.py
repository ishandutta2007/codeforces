n=int(input())
a=[False]*n;b=[False]*n
for i in range(n*n):
    h,v=map(int,input().split())
    h-=1;v-=1
    
    if(not a[h] and not b[v]):
        a[h]=b[v]=True
        print(i+1,end=' ')