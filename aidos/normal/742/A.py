n = int(input())
if n == 0:
    print(1)
else:
    print((8, 4, 2, 6)[(n-1) % 4])