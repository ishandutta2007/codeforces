t = int(input())
for i in range(t):
    g = int(input())
    d = 0
    while g > 0:
        d += g % 2
        g //= 2
    print(2**d)