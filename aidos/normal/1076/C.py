t = int(input())

for i in range(t):
    d = int(input())
    #x^2-d*x+d = 0
    D = d*d - 4 * d
    if D < 0:
        print('N')
        continue
    print('Y', (d-D ** 0.5)/2, (d + D ** 0.5)/2)