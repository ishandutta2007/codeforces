def dot_product(v1, v2):
    return v1.x * v2.x + v1.y * v2.y


class vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def length(self):
        return (self.x ** 2 + self.y ** 2) ** 0.5

    def cross_product(self, v):
        return self.x * v.y - self.y * v.x

class line:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def distance(self, p):
        return abs(vector(p.x - self.a.x, p.y - self.a.y).cross_product(vector(p.x - self.b.x, p.y - self.b.y)) / vector(self.a.x - self.b.x, self.a.y - self.b.y).length())

class ray:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def distance(self, p):
        if dot_product(vector(self.b.x - self.a.x, self.b.y - self.a.y), vector(p.x - self.a.x, p.y - self.a.y)) >= 0:
            return line(self.a, self.b).distance(p)
        return vector(self.a.x - p.x, self.a.y - p.y).length()

class segment:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def min_distance(self, p):
        if dot_product(vector(self.b.x - self.a.x, self.b.y - self.a.y), vector(p.x - self.a.x, p.y - self.a.y)) >= 0:
            return ray(self.b, self.a).distance(p)
        return vector(self.a.x - p.x, self.a.y - p.y).length()

    def max_distance(self, p):
        return max(vector(self.a.x - p.x, self.a.y - p.y).length(), vector(self.b.x - p.x, self.b.y - p.y).length())


n, x, y = map(int, input().split())
p = vector(x, y)

min_r = 2000000
max_r = 0

a = [[] for i in range(n + 1)]

for i in range(n):
    a[i] = list(map(int, input().split()))
    a[i] = vector(a[i][0], a[i][1])

a[n] = a[0]

for i in range(n):
    s = segment(a[i], a[i + 1])
    min_r = min(min_r, s.min_distance(p))
    max_r = max(max_r, s.max_distance(p))

pi = 3.141592653589
print(pi * max_r ** 2 - pi * min_r ** 2)