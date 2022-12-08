n =int(input())
w=[]
h=[]
c=[]
cntw={}
cnth={}
gcdC=0
cntC=0
def insert1(a,b,c):
	if not a in b :
		b[a]=c
	else :
		b[a]=b[a]+c

def gcd(a,b): 
	if a % b == 0 :
		return b
	else :
		return gcd(b,a%b)

for i in range(0, n):
	a,b,d = map(int,input().split())
	w.append(a)
	h.append(b)
	c.append(d)
	insert1(a,cntw,d)
	insert1(b,cnth,d)
	cntC += d
	if gcdC == 0 :
		gcdC = d
	else :
		gcdC = gcd(gcdC, d)

for i in range(0, n):
	if cntw[w[i]] * cnth[h[i]] != cntC * c[i]:
		print (0)
		exit()

ans = 0
i = 1
while (i * i <= gcdC) :
	if gcdC % i == 0 :
		ans += 1
		if i * i != gcdC :
			ans += 1
	i += 1

print (ans)