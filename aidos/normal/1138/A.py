n = int(input())
a = list(map(int, input().split()))
b=[]
c=[]
t=-1
for i in range(n):
    if a[i]==1:
        t=i
    b.append(t)

t=-1
for i in range(n):
    if a[i]==2:
        t=i
    c.append(t)
ans = 0
for i in range(n):
    if b[i] == -1 or c[i] == -1:
        continue
    ans=max(ans, min(c[i]-b[c[i]], b[i] - c[b[i]]))
print(ans*2)