n = int(input())
a = [int(x) for x in input().split()]
for x in a:
	if x == 1:
		print("HARD")
		exit(0)
print("EASY")