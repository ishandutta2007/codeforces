def check(l):
	t = l
	return((l == sorted(t)) or (l == sorted(t,reverse = True)))

t = int(input())
for y in range(t):
	n = int(input())
	l = list(map(int,input().split()))
	f = check(l)
	#print(f)
	if(f == True):
		print("YES")
	else:
		i = 0
		min = 0
		for i in range(1,n):
			if(l[min] > l[i]):
				min = i
		t = l[min:]
		t.extend(l[:min])
		#print(t)
		f = check(t)
		if(f == 1):
			print("YES")
		else:
			max = 0
			for i in range(1,n):
				if(l[max] < l[i]):
					max = i
			t = l[max:]
			t.extend(l[:max])
			#print(t)
			f = check(t)
			if(f == 1):
				print("YES")
			else:
				print("NO")