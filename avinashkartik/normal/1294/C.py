t = int(input())
for y in range(t):
	n = int(input())
	i = 2
	a = n
	ans = []
	while(i*i <= n):
		if(a%i == 0):
			ans.append(i)
			a //= i
		i += 1
		if len(ans) == 2: break
	if(len(ans) != 2):
		print("NO")
	elif(a == ans[0] or a == ans[1]):
		print("NO")
	else:
		print("YES")
		print(ans[0],ans[1],a)