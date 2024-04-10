n, k = map(int, input().split())
A = list(map(int, input().split()))

l = 0
r = n - 1
ans = 0

while l != r + 1:
	if A[l] <= k:
		l += 1
		ans += 1
	elif A[r] <= k:
		r -= 1
		ans += 1
	else:
		break
print(ans)