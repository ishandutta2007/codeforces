s = input()
t = input()

d = {}
e = {}
for c in t:
	d[c] = d.get(c, 0) + 1

for c in s:
	e[c] = e.get(c, 0) + 1

for i in d:
	if d[i] > e.get(i, 0):
		print("need tree")
		exit()

if len(s) == len(t):
	print("array")
	exit()

j = -1
for i in range(len(t)):
	while True:
		j += 1
		if j == len(s):
			print("both")
			exit()
		if s[j] == t[i]:
			break
print("automaton")