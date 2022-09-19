n,k = map(int,input().split())
a = list(map(int,input().split()))
c = list(map(int,input().split()))
s = 0
ss = 0
for i in range(n):
    if c[i] == 1:ss += a[i]
for i in range(k):
    if c[i] == 0:
        s += a[i]
m = s
#print(s)
for i in range(n-k):
    if c[i] == 0:
        s -= a[i]
    if c[i+k] == 0:
        s += a[i+k]
    m = max(m,s)
    #print(s)
print(ss+m)