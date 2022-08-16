from math import *

t = int(input())
for y in range(t):
	n ,m ,k = map(int,input().split())
	h = list(map(int,input().split()))
	for i in range(n-1):
		#print(m)
		if(h[i+1] - h[i] == k):
			continue
		elif(h[i] > h[i+1]):
			s = h[i+1] - k
			if(s < 0):
				m += h[i]
			else:
				m += h[i] - (h[i+1] - k)

		else:
			if(h[i+1] - h[i] < k):
				s = h[i+1] - k
				if(k < h[i+1]):
					m += h[i] - (h[i+1] - k)
				else:
					m += h[i]
			else:
				m -= h[i+1] - k - h[i]
			if(m < 0):
				break
	else:
		print("YES")
		continue
	print("NO")