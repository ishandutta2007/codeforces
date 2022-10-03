n,m=list(map(int,input().split()))
a=list(map(int,input().split()))
cnt=[0]*101
for i in a:
    cnt[i]+=1
cnt.sort(reverse=True)
ans=0
for i in range(1,101):
    k=0
    for j in range(101):
        k+=cnt[j]//i
        if k>=n:
            ans=max(ans,i)
            break
print(ans)