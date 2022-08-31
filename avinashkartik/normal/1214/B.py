b = int(input())
g = int(input())
n = int(input())
s = n+1
m = 0
if(n>g):
	m = n-g
if(n>b):
	m += n-b
print(s-m)