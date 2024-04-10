n,m = map(int,input().split())
a = list(map(int,input().split()))
t = 2
for i in range(1,n):
    di = a[i]-a[i-1]
    if(di==2*m):t+=1
    if(di>2*m):t+=2
print(t)