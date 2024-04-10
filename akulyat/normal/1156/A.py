n=int(input())
m=list(map(int, input().split()))
ans=0
for i in range(n-1):
    if m[i]*m[i+1]==6:
        print("Infinite")
        exit(0)
    if m[i]*m[i+1]==2:
        ans+=3
    if m[i]*m[i+1]==3:
        ans+=4
for i in range(n-2):
    if m[i]==3 and m[i+1]==1 and m[i+2]==2:
        ans-=1
print("Finite\n", ans, sep='')