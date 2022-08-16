def closest(arr,pos):
	n = len(arr)
	low = 0
	up = n-1
	while(up >= low):
	  mid = (up+low)//2
	  ##print(mid)
	  if(arr[mid] == pos):
	  	return mid
	  elif(arr[mid] > pos):
	  	if(arr[mid-1] < pos):
	  		return mid-1
	  	else:    
	  		up = mid - 1
	  else:
	  	if(arr[mid+1] > pos):
	  		return mid
	  	else:
	  		low = mid + 1


t = int(input())
n = 1
a = []
while(n<100000):
	a.append(n*(n+1)//2)
	n += 1

for i in range(t):
	n = int(input())
	s = ['1','3','3']
	no3 = closest(a,n)
	no7 = n - a[no3]
	#print(no3,no7)
	s.extend(['7']*no7)
	s.extend(['3']*no3)
	s.append('7')
	print(''.join(s))