n,k,s = map(int,input().split())
j = 1
if s < k or (n - 1) * k < s:
	print("NO")
else:
	print("YES")
	while k > 0:
		dist = min(n - 1,s - k + 1)
		if j + dist <= n:
			j += dist
			print(j,end = ' ')
		elif j - dist > 0:
			j -= dist 
			print(j,end = ' ')
		s -= dist
		k -= 1