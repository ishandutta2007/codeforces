n = int(input())
a = [int(x) for x in input().split()]
b = []
k = 0
x = 0
for i in range(n):
	if i == 0:
		k += 1
		x = a[i] * 2
	else:
		if a[i] <= x:
			k += 1
			x = a[i] * 2
		else:
			b.append(k)
			k = 1
			x = a[i] * 2
b.append(k)
i_max = -1
for y in b:
	if y > i_max:
		i_max = y
print(i_max)