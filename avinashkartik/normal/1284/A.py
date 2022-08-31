n,m = map(int,input().split())
s = list(input().split())
t = list(input().split())
q = int(input())
for y in range(q):
	a = int(input())
	a -= 1
	print(s[a%n]+t[a%m])