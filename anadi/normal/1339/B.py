t = int(input())
for case in range(t):
	n = int(input())
	a = [int(s) for s in input().split()]
	
	a.sort()	
	left, right = (n + 1) // 2, (n + 3) // 2
	ans = [a[left - 1]]
	for i in range(1, n):
		if i & 1:
			ans.append(a[right - 1])
			right += 1
		else:
			left -= 1
			ans.append(a[left - 1])

	for elem in ans:
		print(elem, end = ' ')
	print('')