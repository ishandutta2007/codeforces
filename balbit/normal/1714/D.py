import sys


q = int(input())

for _ in range(q):
	S = input()
	n = len(S)
	m = int(input())
	ss = []
	for i in range(m):
		x = input()
		ss.append(x)
	dp = [1000000] * (n+1)
	frm = [[-1,-1]] * (n+1)
	dp[0] = 0
	for i in range(n):
		for j in range(m):
			if i + len(ss[j]) <= n and S[i:i+len(ss[j])] == ss[j]:
				# print(i,j,"hi")
				for k in range(len(ss[j])):
					if dp[i]+1 < dp[i+k+1]:
						dp[i+k+1] = dp[i]+1
						frm[i+k+1] = [i,j]

	if dp[n] == 1000000:
		print(-1)
	else:
		at = n
		print(dp[n])
		while at != 0:
			print(frm[at][1]+1, frm[at][0]+1)
			at = frm[at][0]