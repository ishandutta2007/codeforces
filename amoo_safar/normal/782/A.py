n = int(input())
a = list(map(int,input().split()))
c=[0]*n
m = 0
t = 0
for i in a:
    if c[i-1]==0:
        c[i-1] = 1
        t+=1
        m = max(m,t)
    else:
        c[i-1] = 0
        t-=1
print(max(m,t))