n,k = map(int,input().split())
a = [int(x) for x in input().split()]
b = a[::]
b.sort(reverse = True)
b = b[:k]
su = 0
for x in b:
	su += x
print(su)
i = 0
pred = -1
while i < n and len(b) > 1:
	j = -1
	for q in range(len(b)):
		if b[q] == a[i]:
			j = q
	if j != -1:
		print(i - pred,end = ' ')
		pred = i
		i += 1
		b = b[:j] + b[j + 1:len(b)]
	else:
		i += 1
print(n - pred - 1)