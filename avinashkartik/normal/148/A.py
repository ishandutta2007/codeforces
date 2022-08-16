k = int(input())
l = int(input())
m = int(input())
n = int(input())
d = int(input())
ans = [0 for i in range(d+1)]
for i in range(k,d+1,k):
	ans[i] = 1
for i in range(l,d+1,l):
	ans[i] = 1
for i in range(m,d+1,m):
	ans[i] = 1
for i in range(n,d+1,n):
	ans[i] = 1
print(ans.count(1))