n, t = map(int, input().split())
a = [int(x) for x in input().split()]

otv = 0

def rec(t, a):
	global otv
	s = 0
	for c in a:
		s += c
	kol = t // s
	kol = max(kol, 0)
	otv += (kol * len(a))
	octat = t - kol * s
	res = []
	su = 0
	for c in a:
		if su + c <= octat:
			res.append(c)
			su += c
	if su == 0:
		print(otv)
		exit(0)
	#print(octat, res, otv)
	rec(octat, res)

rec(t, a)