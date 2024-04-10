n, r = map(int,input().split())
a = [int(x) for x in input().split()]
if n == 1:
    if a[0] == 0:
        print(-1)
    else:
        print(1)
    exit(0)
kor = []
for i in range(n):
	if a[i] == 1:
		kor.append([max(i - r + 1,0),min(i + r - 1,n - 1)])
if len(kor) == 0:
	print(-1)
	exit(0)
if kor[0][0] != 0:
	print(-1)
	exit(0)
if kor[len(kor) - 1][1] != n - 1:
	print(-1)
	exit(0)
r = 0
i = 0
kol_t = 0
r_itog = 0
r = 0
while i < len(kor) and r_itog < n - 1:
	f = True
	while i < len(kor) and ((kor[i][0] <= r + 1 and kol_t != 0) or (kor[i][0] <= r)):
		r_itog = max(r_itog,kor[i][1])
		i += 1
		f = False
	if f:
		print(-1)
		exit(0)
	r = r_itog
	kol_t += 1
print(kol_t)