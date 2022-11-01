n=int(raw_input())
a=raw_input()
b=raw_input()
nomin,nomax,all,noboth=1,1,1,1
for i in range(n):
    if a[i]=='?':
        all=all*10
    if b[i]=='?':
        all=all*10
    all=all % 1000000007

        
for i in range(n):
    if a[i]<b[i] and a[i]!='?' and b[i]!='?':
        nomin=0
    if a[i]=='?' and b[i]=='?':
        nomin=nomin*55
    if a[i]=='?' and b[i]!='?':
        nomin=nomin*(10-int(b[i]))
    if a[i]!='?' and b[i]=='?':
        nomin=nomin*(int(a[i])+1)
    nomin=nomin%1000000007

for i in range(n):
    if a[i]>b[i] and a[i]!='?' and b[i]!='?':
        nomax=0
    if a[i]=='?' and b[i]=='?':
        nomax=nomax*55
    if a[i]=='?' and b[i]!='?':
        nomax=nomax*(int(b[i])+1)
    if a[i]!='?' and b[i]=='?':
        nomax=nomax*(10-int(a[i])) 
    nomax=nomax%1000000007 

for i in range(n):
    if a[i]!='?' and b[i]!='?' and a[i]!=b[i]:
        noboth=0
    if a[i]=='?' and b[i]=='?':
        noboth = noboth*10
    noboth=noboth%1000000007
print(all-nomin-nomax+noboth)%1000000007