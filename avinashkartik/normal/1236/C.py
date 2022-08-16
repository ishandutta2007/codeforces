n = int(input())
l = [[]for i in range(n)]
i = 0
key = 0
go = 0
j = n*n
while(j > 0):
	for k in range(n):
		l[k].append(j)
		j -= 1
	for k in range(n-1,-1,-1):
		l[k].append(j)
		j -= 1

for i in l:
	for j in range(n):
		print(i[j],end = " ")
	print()