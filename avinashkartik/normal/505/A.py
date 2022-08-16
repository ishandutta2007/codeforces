s = input()
for j in range(len(s)+1):
	for i in range(26):
		t = s[:j]+chr(i+ord('a'))+s[j:]
		if(t == t[::-1]):
			print(t)
			exit(0)
print("NA")