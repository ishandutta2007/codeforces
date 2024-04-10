n = int(input())
for i in range(n):
	s,a,b,c = map(int,input().split())
	kol = s // c
	print(kol + kol // a * b)