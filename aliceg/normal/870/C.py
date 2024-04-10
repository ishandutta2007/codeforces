q = int(input())
for i in range(q):
    n = int(input())
    if n % 4 == 0:
        print(n // 4)
    elif n % 4 == 1 and n // 4 >= 2:
        print(n // 4 - 1)
    elif n % 4 == 2 and n // 4 >= 1:
        print(n // 4)
    elif n % 4 == 3 and n // 4 >= 3:
        print(n // 4 - 1)
    else:
        print(-1)