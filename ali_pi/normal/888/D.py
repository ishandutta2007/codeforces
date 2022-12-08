n,k=map(int,raw_input().split())
ans=1
p=[0,1,1,2,9]
t=n
for i in range(2,k+1):
    t=t*(n-i+1)//i
    ans+=t*p[i]
print(ans)