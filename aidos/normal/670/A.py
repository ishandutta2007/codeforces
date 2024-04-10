n = int(input())
if n == 1:
    print(0, 1)
elif n <= 5:
    print(0, 2)
else:
    a = 0
    b = 0
    if n % 7 == 6:
        a += 1
    a += (n//7) * 2
    if (n-2) % 7 == 6:
        b += 1
    b += ((n-2)//7) * 2
    print(a, b+2)