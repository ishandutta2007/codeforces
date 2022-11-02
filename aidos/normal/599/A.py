a, b, c = map(int, input().split())

c = min(a+b, c)
a = min(b+c, a)
b = min(a+c, b)
print(a+b+c)