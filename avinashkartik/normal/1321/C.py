ans = 1e8
def solve(x,n):
	global ans
	ans = min(ans,n)
	res = 'a'
	for i in range(n-1):
		if abs(ord(x[i])-ord(x[i+1])) == 1:
			if x[i] > x[i+1]:
				res = max(res,x[i])
			else:
				res = max(res,x[i+1])
	if res == 'a': return
	for i in range(n-1):
		if abs(ord(x[i])-ord(x[i+1])) == 1:
			if x[i] > x[i+1] and x[i] == res:
				solve(x[:i]+x[i+1:],n-1)
				break
			elif x[i] < x[i+1] and x[i+1] == res:
				solve(x[:i+1]+x[i+2:],n-1)
				break

n = int(input())
s = input()
solve(s,n)
print(n-ans)