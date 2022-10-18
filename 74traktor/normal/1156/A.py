n= int(input())
a = [int(x) for x in input().split()]
for i in range(n - 1):
	if min(a[i], a[i + 1]) == 2 and max(a[i], a[i + 1]) == 3:
		print("Infinite")
		exit(0)
print("Finite")
ans = 0
for i in range(n - 1):
	if min(a[i], a[i + 1]) == 1 and max(a[i], a[i + 1]) == 2:
		ans += 3
		if i >= 1:
			if a[i - 1] == 3:
				ans -= 1
	elif min(a[i], a[i + 1]) == 1:
		ans += 4
print(ans)