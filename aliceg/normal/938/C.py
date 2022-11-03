t = int(input())
for k in range(t):
    x = int(input())
    if x == 0:
        print(1, 1)
        continue
    for i in range(1, int(x ** 0.5) + 2):
        if x % i == 0 and (x // i - i) % 2 == 0 and (x // i - (x // i - i) // 2) ** 2 >= x:
            a, b = x // i, i
            y = (a - b) // 2
            n = a - y
            if y == 0:
                continue
            m = n // y
            if n // m != y:
                continue
            print(n, m)            
            break
    else:
        print(-1)