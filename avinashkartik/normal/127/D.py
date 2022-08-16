def LPS(pat): 
	M = len(pat) 
	j = 0
	lps = [0 for i in range(M)]
	i = 1
	while i < M: 
		if pat[i]== pat[j]: 
			j += 1
			lps[i] = j
			i += 1
		else: 
			if j != 0: 
				j = lps[j-1]
			else: 
				lps[i] = 0
				i += 1
	return lps
s = input()
lps = LPS(s)
ans = lps[-1]
ct = 0
for i in range(len(s)):
	if(lps[i] == ans):
		ct += 1
if(ct < 2):
	ans = lps[ans-1]
if(ans > 0):
	print(s[:ans])
else:
	print("Just a legend")