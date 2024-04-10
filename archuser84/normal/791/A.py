a, b = map(int, input().split())
x = 0
while a <= b:
    a *= 3
    b *= 2
    x += 1
print(x)