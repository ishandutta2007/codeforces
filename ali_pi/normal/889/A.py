import sys
n = input()
arr = list(map(int, raw_input().split()))
tail = [0 for i in range(n+1)]
ans = 1
for i in range(1, len(arr)+1):
	x = arr[i-1]
	if tail[x]:
		ans += 1
	else:
		tail[x] = 1

print(ans)