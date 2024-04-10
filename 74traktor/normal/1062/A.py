n = int(input())
a = [int(x) for x in input().split()]
a = [0] + a + [1001]
max_res = 1
for i in range(len(a)):
	for j in range(i + 1,len(a)):
		if a[j] - a[i] == j - i:
			max_res = max(max_res, j - i)
print(max_res - 1)