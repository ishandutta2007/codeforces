t = int(input())

def ask(p, s):
	need = 0
	cnt = 0
	for v in s:
		if v == p[need]:
			cnt += 1
			need ^= 1
	
	if p[0] != p[1] and cnt % 2 == 1:
		cnt -= 1
	return cnt

for _ in range(t):
	s = input()
	ans = 2
	
	for i in range(10):
		for j in range(10):
			ans = max(ans, ask((str(i), str(j)), s))
	print(len(s) - ans)