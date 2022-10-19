s = input()
n = int(input())
if n > len(s):
	print("impossible")
else:
	was = [False] * 26
	for i in s:
		was[ord(i) - ord('a')] = True
	dif = 0
	for i in was:
		if i:
			dif += 1
	print(max(0, n - dif))