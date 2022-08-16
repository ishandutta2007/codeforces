def check(A,B,C):
	x = a.index(A)
	y = a.index(B)
	z = a.index(C)
	if((y-x)%12 == 4 and (z-y)%12 == 3):
		print("major")
		exit(0)
	elif((y-x)%12 == 3 and (z-y)%12 == 4):
		print("minor")
		exit(0)

a = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'B', 'H']
A,B,C = input().split()
check(A,B,C)
check(A,C,B)
check(B,A,C)
check(B,C,A)
check(C,A,B)
check(C,B,A)
print("strange")