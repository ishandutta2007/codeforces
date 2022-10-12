import math

n, m, a = tuple(float(i) for i in raw_input().strip().split(" "))

x = math.ceil(n/a)
y = math.ceil(m/a)
print int(x*y)