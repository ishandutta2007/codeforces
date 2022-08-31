s = input()
i,j = 0,len(s)-1
ans = []
while(i < j):
	while(i < j and s[i] == ')'): i += 1
	while(i < j and s[j] == '('): j -= 1
	if(i < j):
		ans.extend([i+1,j+1])
		i += 1
		j -= 1
if(len(ans) == 0):
	print(0)
else:
	print(1)
	print(len(ans))
	ans.sort()
	print(*ans)