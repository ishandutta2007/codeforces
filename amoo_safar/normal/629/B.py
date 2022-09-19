n = int(input())
f = [0]*366
m = [0]*366
for i in range(n):
    a,b,c = input().split()
    if a=='F':
        for j in range(int(b)-1,int(c)):f[j]+=1
    if a=='M':
        for j in range(int(b)-1,int(c)):m[j]+=1
ans = 0
for i in range(366):
    t = min(m[i],f[i])
    ans = max(ans,t)
print(ans*2)