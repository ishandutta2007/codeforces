from bisect import bisect
from sys import exit

[n, k, d] = map(int,raw_input().strip().split())
ais = list(map(int,raw_input().strip().split()))
if k == 1:
	print ('YES')
	exit()

ais.sort()

# can do ais[i:]
cando = [False for _ in range(n)]
j = n - 1 
count = 0 
for i in reversed(range(n)):
	if i + k < n and cando[i + k]:
		count += 1
	if n - i < k:
		continue
	if ais[-1] - ais[i] <= d:
		cando[i] = True
		continue
	while ais[j - 1] > ais[i] + d:
		if cando[j]:
			count -= 1
		j -= 1
	cando[i] = (count > 0)
	

if cando[0]:
	print ('YES')
else:
	print ('NO')