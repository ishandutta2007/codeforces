n = int(input())
a = 1
b = 1
k = 0
while a <= n:
    a, b = a + b, a
    k += 1
print(k - 1)