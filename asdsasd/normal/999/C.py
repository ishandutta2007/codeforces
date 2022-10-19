n, k = map(int, input().split())
S = list(input()) 
rem = [False] * n
for i in range(26):
	x = chr(i + 97)
	for j in range(n):
		if S[j] == x:
			rem[j] = True
			k -= 1
			if k == 0:
				break
	if k == 0:
		break

T = []
for i in range(n):
	if not rem[i]:
		T.append(S[i])
print(*T, sep="")