t = int(input())
for y in range(t):
	n0,n1,n2 = map(int,input().split())
	s = ''
	if(n1 or n2): s += '1'*(n2+1)
	if(n1): s += '01'*((n1-1)//2)
	if(n1 or n0): s += '0'
	s += '0'*(n0)
	if(n1%2==0 and n1 > 0): s = '0'+s
	print(s)