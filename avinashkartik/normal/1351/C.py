t = int(input())
for y in range(t):
	s = input()
	ct = 0
	n = dict()
	e = dict()
	w = dict()
	ss = dict()
	x,y = 0,0
	for i in s:
		dx,dy = x,y
		if i == 'N':
			dx += 1
			if (x,y) in ss or (dx,dy) in n:
				ct += 1
			else:
				ct += 5
				n[(dx,dy)] = 1
		if i == 'E':
			dy += 1
			if (x,y) in w or (dx,dy) in e:
				ct += 1
			else:
				ct += 5
				e[(dx,dy)] = 1
		if i == 'W':
			dy -= 1
			if (x,y) in e or (dx,dy) in w:
				ct += 1
			else:
				ct += 5
				w[(dx,dy)] = 1
		if i == 'S':
			dx -= 1
			if (x,y) in n or (dx,dy) in ss:
				ct += 1
			else:
				ct += 5
				ss[(dx,dy)] = 1
		x = dx
		y = dy
	print(ct)