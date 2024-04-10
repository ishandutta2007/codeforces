n = int(input())
a = input()
c = a.count('A')
if c + c > n:
	print("Anton")
elif c + c < n:
	print("Danik")
else:
	print("Friendship")