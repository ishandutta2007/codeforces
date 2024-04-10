a, b = list(map(int, input().split()))
c, d = list(map(int, input().split()))

t1 = b
t2 = d
solution_found = False

for i in range(10000):
	if (t1 == t2):
		print(t1)
		solution_found = True
		break
	elif (t1 > t2):
		t2 += c
	else:
		t1 += a

if (not solution_found):
	print(-1)