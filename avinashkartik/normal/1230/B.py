n,k = map(int,input().split())
s = list(input())
ct = 0
if(n == 1 and k >0):
	print(0)
else:
	for i in range(n):
		if(ct >= k):
			break
		if(i == 0 and s[i] != '1'):
			s[i] = '1'
			ct += 1
		elif(i > 0 and s[i] != '0'):
			s[i] = '0'
			ct += 1
	for i in range(n):
		print(s[i],end = "")
	print()