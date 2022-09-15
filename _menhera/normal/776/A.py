X,Y = input().split()
print (X, Y)
for i in range(int(input())):
	A, B = input().split()
	if X==A: X = B
	elif Y==A: Y = B
	print(X,Y)