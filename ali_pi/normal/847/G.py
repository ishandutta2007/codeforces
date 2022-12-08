n = int(raw_input())
a = [0]*7
for i in range(n):
	b = raw_input()
	for j in range(7):
		a[j] += int(b[j])
print(max(a))