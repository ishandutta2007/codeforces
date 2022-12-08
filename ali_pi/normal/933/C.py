from math import sqrt

class vector:
	def __init__(self, _x = 0, _y = 0):
		self.x = _x
		self.y = _y
	def len(self):
		return sqrt(self.x ** 2 + self.y ** 2)
	def len_sq(self):
		return self.x ** 2 + self.y ** 2
	def __mul__(self, other):
		if (type(self) == type(other)):
			return self.x * other.x + self.y * other.y
		return vector(self.x * other, self.y * other)
	def __mod__(self, other):
		return self.x * other.y - self.y * other.x
	def normed(self):
		length = self.len()
		return vector(self.x / length, self.y / length)
	def normate(self):
		self = self.normed()
	def __str__(self):
		return "(" + str(self.x) + ", " + str(self.y) + ")"
	def __add__(self, other):
		return vector(self.x + other.x, self.y + other.y);
	def __sub__(self, other):
		return vector(self.x - other.x, self.y - other.y);
	def __eq__(self, other):
		return self.x == other.x and self.y == other.y
	def rot(self):
		return vector(self.y, -self.x)

class line:
	def __init__(self, a = 0, b = 0, c = 0):
		self.a = a
		self.b = b
		self.c = c
	def intersect(self, other):
		d = self.a * other.b - self.b * other.a
		dx = self.c * other.b - self.b * other.c
		dy = self.a * other.c - self.c * other.a
		return vector(dx / d, dy / d)
	def fake(self, other):
		d = self.a * other.b - self.b * other.a
		return d
	def __str__(self):
		return str(self.a) + "*x + " + str(self.b) + "*y = " + str(self.c) 

def line_pt(A, B):
		d = (A - B).rot()
		return line(d.x, d.y, d * A)

class circle:
	def __init__(self, O = vector(0, 0), r = 0):
		self.O = O
		self.r = r
	def intersect(self, other):
		O1 = self.O
		O2 = other.O
		r1 = self.r
		r2 = other.r
		if (O1 == O2):
			return []
		if ((O1 - O2).len_sq() > r1 ** 2 + r2 ** 2 + 2 * r1 * r2):
			return []
		rad_line = line(2 * (O2.x - O1.x), 2 * (O2.y - O1.y), r1 ** 2 - O1.len_sq() - r2 ** 2 + O2.len_sq())
		central = line_pt(O1, O2)
		M = rad_line.intersect(central)
		if ((O1 - O2).len_sq() == r1 ** 2 + r2 ** 2 + 2 * r1 * r2):
			return [M]
		d = (O2 - O1).normed().rot()
		if (r1 ** 2 - (O1 - M).len_sq() < 0):
			return []
		d = d * (sqrt(r1 ** 2 - (O1 - M).len_sq()))
		return [M + d, M - d]
	def fake(self, other):
		O1 = self.O
		O2 = other.O
		r1 = self.r
		r2 = other.r
		if (O1 == O2):
			return 1
		if ((O1 - O2).len_sq() > r1 ** 2 + r2 ** 2 + 2 * r1 * r2):
			return 1
		rad_line = line(2 * (O2.x - O1.x), 2 * (O2.y - O1.y), r1 ** 2 - O1.len_sq() - r2 ** 2 + O2.len_sq())
		central = line_pt(O1, O2)
		return rad_line.fake(central)
n = input()
arr = []
m = 1
for i in range(n):
	x, y, r = map(int, raw_input().split())
	arr.append(circle(vector(x, y), r))
for i in range(n):
	for j in range(i + 1, n):
		m *= arr[i].fake(arr[j])
for i in range(n):
	arr[i].O = arr[i].O * m
	arr[i].r = arr[i].r * m
s = set()
V = 0
for i in range(n):
	for j in range(i + 1, n):
		tmp = arr[i].intersect(arr[j])
		for e in tmp:
			s.add((round(e.x, 6), round(e.y, 6)))
V += len(s)
E = 0

par = [i for i in range(n)]

def get_par(v):
	if (par[v] != v):
		par[v] = get_par(par[v])
	return par[v]
def unite(v, u):
	par[get_par(v)] = get_par(u)
for i in range(n):
	s = set()
	for j in range(n):	
		tmp = arr[i].intersect(arr[j])
		if (len(tmp)):
			unite(i, j)
		for e in tmp:
			s.add((round(e.x, 	), round(e.y, 	)))
	E += len(s)
print(E - V + 1 + len({get_par(i) for i in range(n)}))