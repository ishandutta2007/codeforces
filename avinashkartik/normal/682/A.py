x,y = map(int,input().split())
ans = 0
for i in range(5):
	j = (5-i)%5
	cti = x//5
	if(i and x%5 >= i): cti += 1
	ctj = y//5
	if(j and y%5 >= j): ctj += 1
	ans += cti*ctj
print(ans)