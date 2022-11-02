n = int(input())
a = int(input())
b = int(input())
c = int(input())
n -= 1
if n == 0:
    print(0)
elif min(a, b, c) == c:
    print(min(a, b) + (n-1) * c)
else:
    print(min(a, b, c) * n )