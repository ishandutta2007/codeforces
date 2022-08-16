t = int(input())
for y in range(t):
	s = list(input())
	t = list(input())
	flag = 0
	for i in t:
		if i in s:
			flag = 1
			break
		if flag == 1:
			break
	if(flag == 1):
		print("YES")
	else:
		print("NO")