from math import *
import sys
sys.setrecursionlimit(10**9)
ff = 0
def dfs(x,vis,par,ans,ch,st,anss):
	global ff
	#print(x,par)
	if(vis[x] == 0):
		vis[x] = 1
		if(ch == 0):
			anss.append(chr(x+ord('a')))
		else:
			anss.insert(0,chr(x+ord('a')))
		for i in ans[x]:
			if(i == par): continue
			dfs(i,vis,x,ans,ch,st,anss)
			if(x == st): ch = 1
	else:
		ff = 1

t = int(input())
for y in range(t):
	ff = 0
	s = input()
	n = len(s)
	ans = [[] for i in range(26)]
	vis = [0 for i in range(26)]
	flag = 1
	for i in range(1,n):
		ind = ord(s[i]) - ord('a')
		ind1 = ord(s[i-1]) - ord('a')
		if(ind1 not in ans[ind]):
			ans[ind].append(ind1)
			ans[ind1].append(ind)
			if(len(ans[ind]) > 2 or len(ans[ind1]) > 2):
				flag = 0
				break
	if(flag == 0):
		print("NO")
	else:
		#print(ans)
		ansss = []
		for i in range(26):
			if(vis[i] == 0):
				anss = []
				dfs(i,vis,-1,ans,0,i,anss)
				ansss.extend(anss)
		if(ff == 0):
			print("YES")
			print("".join(ansss))
		else:
			print("NO")