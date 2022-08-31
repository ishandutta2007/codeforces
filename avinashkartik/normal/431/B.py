ans = 0
def rec(ind, l):
	global ans
	if(ind == 5):
		res = 0
		for i in range(4):
			s = a[l[i]][l[i+1]]+a[l[i+1]][l[i]]
			res += s*(1+i//2)
		ans = max(ans,res)
		return
	else:
		for i in range(5):
			if i not in l:
				l.append(i)
				rec(ind+1,l)
				l.pop()
a = []
for i in range(5):
	a.append(list(map(int,input().split())))
rec(0,[])
print(ans)