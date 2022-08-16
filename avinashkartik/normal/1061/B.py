n,m = list(map(int,input().split()))
a = list(map(int,input().split()))
a.sort(reverse = True)
m = a[0]
ct = 0
for i in range(n):
	if(m == 0):
		ct += n-i
		break
	ct += 1
	if(a[i] < m):
		ct += m-a[i]
		m = a[i]
	m -= 1
print(sum(a)-(m+ct))