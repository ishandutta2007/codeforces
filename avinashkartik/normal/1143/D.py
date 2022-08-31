def gcd(a,b):
    if(b == 0):
        return a
    else:
        return gcd(b,a%b)

n,k = map(int,input().split())
a,b = map(int,input().split())
l = [b-a,-a-b]
g = []
for i in range(n):
    for j in range(2):
        u = k*i + l[j]
        m1 = gcd(u,n*k)
        g.append(m1)
#print(g)
max1 = min(g)
max2 = n*k//max1
min1 = max(g)
min2 = n*k//min1
if(a == b):
    min2 = 1
if(a == 0 and b == 0):
    max2 = n
print(min2,max2)