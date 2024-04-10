n=input()
p=list(map(int,raw_input().split()))
a=[0]*n
t=s=f=0
for i in range(n):
    if p[i]<=t:a[i]=t-p[i]+1
    t=max(p[i],t+1)
for i in range(n-1,0,-1):
    if p[i] <= s: a[i] = min(s - p[i] + 1,a[i])
    else:a[i]=0
    s = max(p[i], s + 1)
for i in range(n):p[i]+=a[i];f|=i>1and p[i]==p[i-1]
print(sum(a[:])+f)