a=list(map(int, raw_input().split()))
n,m=a[0],a[1]
ans=0
a=list(map(str, raw_input().split()))
for i in range(n):
    s=a[i]
    qua=0
    for j in range(len(s)):
        if s[j]=='4' or s[j]=='7':
            qua+=1
    if qua<=m:
        ans+=1
print(ans)