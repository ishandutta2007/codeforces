t = int(input())
for i in range(t):
    n = int(input())
    a = n
    for i in range(2, 35000):
        if n % i == 0:
            a = i
            break
    n //= a
    b = n
    for i in range(2, 35000):
        if n % i == 0 and a != i:
            b = i
            break
    n //= b
    if n == 1 or n == a or n == b:
        print("NO")
    else:
        print('YES')
        print(a, b, n)