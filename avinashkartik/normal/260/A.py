a,b,n = input().split()
b = int(b)
m = (int(a)*10)%b
for j in range(10):
	if (m+j)%b == 0:
		a += str(j)
		m = 0
		break
else:
	print(-1)
	exit(0)
print(a+'0'*(int(n)-1))