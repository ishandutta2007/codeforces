n,k = list(map(int,input().split()))
if(n < k*(k+1)/2):
	print("NO")
	exit(0)
dif = n - k*(k+1)//2
a = [i+1+dif//k for i in range(k)]
dif %= k
if(dif == 0):
	print("YES")
	print(*a)
	exit(0)
if(a[-1]+dif > 2*a[-2]):
	if(k == 2):
		print("NO")
		exit(0)
	if(a[-2] == 2*a[-3]):
		print("NO")
		exit(0)
	a[-2] += 1
	a[-1] += dif-1
else:
	a[-1] += dif
print("YES")
print(*a)