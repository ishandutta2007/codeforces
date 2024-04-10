n = int(input())
a = [int(x) for x in input().split()]
k = 0
for i in range(2, n):
	if a[i - 1] == 0 and a[i - 2] == 1 and a[i] == 1:
		a[i] = 0
		k += 1
print(k)