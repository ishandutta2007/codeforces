for tc in range(input()):
    n = input()
    if n % 2 == 0:
        print(n // 4 if n >= 4 else -1)
    elif n == 9:
        print(1)
    else:
        print((n - 9) // 4 + 1 if n >= 13 else -1)