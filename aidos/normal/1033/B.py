t = int(input())
for i in range(t):
    a, b = map(int, input().split())
    good = 1
    if abs(a-b) != 1:
        good = 0
    i = 2
    a += b
    while i * i <= a and good == 1:
        if a % i == 0:
            good = 0
        i += 1
    print(('NO', 'YES')[good])