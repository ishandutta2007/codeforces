a=[*map(int,[*open(0)][1].split())]
for k in 0,1:
	for i in range(19):
		z=1<<i
		for j in range(len(a)):
			if j&z:a[j-k*z]^=a[j+k*z-z]
print(*reversed(a))