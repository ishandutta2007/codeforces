n, k = list(map(int, input().split()))
s = input()
num = [0] * 26
for i in s:
	num[ord(i) - ord('a')] += 1
ans = True
for i in num:
	if i > k:
		ans = False
		break
if ans:
	print("YES")
else:
	print("NO")