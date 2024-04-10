def makeUnique(s):
	return s.lower().replace('i', '1').replace('o', '0').replace('l', '1')

login = makeUnique(input())
for i in range(int(input())):
	if makeUnique(input()) == login:
		print('No')
		exit()
print('Yes')