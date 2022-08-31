n = int(input())
s = input()
arr = [[] for i in range(26)]
for i in range(n):
	ind = ord(s[i]) - ord('a')
	arr[ind].append(i)
q = int(input())
for i in range(q):
	t = input()
	a = [0 for i in range(26)]
	m = 0
	for j in t:
		ind = ord(j) - ord('a')
		m = max(arr[ind][a[ind]],m)
		a[ind] += 1
	print(m+1)