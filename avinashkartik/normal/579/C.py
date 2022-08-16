def bs(R):
	l = 1
	r = R
	ans = R
	while(l <= r):
		mid = (l+r)//2
		if(R/mid > y):
			ans = mid
			l = mid + 1
		else:
			r = mid - 1
	if(ans&1): ans -= 1
	return R/ans
x,y = map(int,input().split())
if(x < y):
	print(-1)
elif(x == y):
	print(x)
elif(x%y == 0 and (x//y)%2 == 1):
	print(y)
else:
	print(bs(x+y))