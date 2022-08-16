n = int(input())
a = [7,1]
b = [3,5]
last = 0 
if(n % 2):
	print("YES")
	print(1,end = " ")
	i = 2*n
	while(i >= 3):
		print(i,end = " ")
		last = i
		i -= a[i%2]
	if(last == 3):
		i = 6
	else:
		i = 3
	while(i <= (2*n - 3)):
		print(i,end = " ")
		i += a[i%2 - 1]
	print(2,end = " ")
	i = 2*n - 1
	while(i >= 4):
		print(i,end = " ")
		last = i
		i -= b[i%2]
	if(last == 4):
		i = 5
	else:
		i = 4
	while(i <= (2*n - 2)):
		print(i,end = " ")
		i += b[i%2 - 1]
else:
	print("NO")