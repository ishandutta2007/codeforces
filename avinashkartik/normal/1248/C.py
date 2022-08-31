n,m = map(int,input().split())
a = [0,2]
mod = pow(10,9)+7
s = 0
t = 2
for i in range(2,100002):
    u = ((a[i-1]*2)%mod - s%mod)%mod
    if(u < 0):
        u += mod
    a.append(u)
    s = t
    t = (u%mod-s%mod)%mod
    if(t < 0):
        t += mod
#print(a[-1])
print(((a[n]%mod)+(a[m]%mod)-2)%mod)