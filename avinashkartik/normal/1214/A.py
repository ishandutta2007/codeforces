n = int(input())
e = int(input())
d1 = int(input())
d = 5*d1

n1 = n
while(n1 >= 0):
	if(n1 % d < n1 % e):
		if(n1 >= d):
			n1 -= d
		else:
			break
	else:
		if(n1 >= e):
			n1 -= e
		else:
			break

print(n1)