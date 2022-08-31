n = int(input())
s = list(map(int,input().split()))
a = s[::]
s.sort(reverse = True)
c = 0
for i in range(n):
	#print(a[i][0])
	c += i*s[i] + 1
print(c)
for i in range(n):
	for j in range(n):
		if(a[j] == s[i]):
			print(j+1,end = " ")
			a[j] = -1
			break
print()