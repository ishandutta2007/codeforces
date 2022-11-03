n = int(input())
a = list(input().split())
for i in range(n):
	a[i] = ''.join(sorted(list(set(a[i]))))
print(len(set(a)))