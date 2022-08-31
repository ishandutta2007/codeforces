def summ(x):
	return x*(x+1)//2
a,b,c,d = map(int,input().split())
ans = 0
for i in range(a,b+1):
	lb = i+b
	if(lb > d):
		ans += (c-b+1)*(d-c+1)
		continue
	x = b
	if(lb < c):
		rb = 0
		x = c-i
	if(i > d-c+1):
		ans += (i-(d-c+1))*(d-c+1)
	ans += summ(min(d-c+1,c+i-c)) - summ(max(0,x+i-c-1))
print(ans)