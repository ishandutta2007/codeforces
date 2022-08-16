n = int(input())
ct = 0
for i in range(60):
	x = 1<<i
	if(n&x == x):
		ct += 1
print(ct)