n = int(input())
k = list(map(int, input().split()))
ans = int(0)
now = int(1)
last = int(0)
kol = int(0)
if k[n - 1] == 1:
    k.append(0)
else:
    k.append(1)
for i in range(n):
	if k[i] == k[i + 1]:
		now = now + 1
	else:
		kol = kol + 1
		if kol == 1:
			last = now
		else:
			if last != now:
				print("NO")
				exit()
			else:
				last = now
		now = 1
print("YES")