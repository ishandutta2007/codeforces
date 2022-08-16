n = int(input())
a = list(map(int,input().split()))
l = [4,8,15,16,23,42]
d = [[] for i in range(6)]
ind = [0,0,0,0,0,0]
ct = 0
for i in range(n):
	j = l.index(a[i])
	d[j].append(i)
p = -1
j = 0
#print(d)
while(1):
	for i in range(ind[j],len(d[j])):
		if(d[j][i] >= p):
			ind[j] = i+1
			p = d[j][i]+1
			j += 1
			break
	else:
		break
	if(j == 6):
		p = -1
		j = 0
		ct += 1
print(n-ct*6)