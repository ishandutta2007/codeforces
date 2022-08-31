s = input()
s = s.lower()
#print(s)
a = ["a","e","i","o","u","y"]
s = list(s)
s.append(';')
n = len(s)
i = 0
while(s[i] != ';'):
	if s[i] not in a:
		s.insert(i,'.')
		i += 2
	else:
		s.remove(s[i])
for i in s:
	if i != ';':
		print(i,end = "")
print()