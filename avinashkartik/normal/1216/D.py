def gcd(a,b):
    if(b == 0):
        return a
    else:
        return gcd(b,a%b)

n = int(input())
l = list(map(int,input().split()))
m = max(l)
z = 0
y = 0
for i in range(n):
	#print(m,m-l[i])
	z = gcd(z,m-l[i])
for i in range(n):
	y += (m-l[i])//z
print(y,z)