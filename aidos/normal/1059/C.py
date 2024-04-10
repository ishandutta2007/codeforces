n = int(input())
x = 1
while True:
    if n == 1:
        print(x, end = ' ')
        break
    if n == 2:
        print(x, x * 2, end = ' ')
        break
    if n == 3:
        print(x, x, x * 3, end = ' ')
        break
    d = n//2
    for i in range(n-d):
        print(x, end = ' ')
    n = d
    x *= 2