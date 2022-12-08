import sys
n,x,y = map(int,input().split())

nn = []
ch = [False] * 10

def ask():
	if len(nn) == 0:
		return False
	print('?',len(nn),end = ' ')
	for i in nn:
		print(i,end = ' ')
	print()
	sys.stdout.flush()
	res = int(input())
	v = 0
	if len(nn) % 2 == 1:
		v = x
	return v!=res

for i in range(10):
	for j in range(1,n+1):
		if j & (1 << i):
			nn.append(j)
	ch[i] = ask()
	nn.clear()

p = 0
for i in range(10):
	if ch[i] == True:
		p = i
		break
a1,a2 = 0,1<<p
for i in range(10):
	if i == p:
		continue
	for j in range(1,n+1):
		if j & 1<<i and j & 1<<p:
			nn.append(j)
	res = ask()
	if res == True:
		a2 += 1<<i 
	if res^ch[i] == True:
		a1 += 1<<i 
	nn.clear()

if a1>a2:
	a1,a2 = a2,a1
print('!',a1,a2)