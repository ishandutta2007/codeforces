n=int(input())
a=list(map(int,input().split()))
b=min(a)
now=-1
ans=1000000
for i in range(len(a)):
    if(a[i]==b):
        if(now!=-1):
            ans=min(ans,i-now)
        now=i

print(ans)