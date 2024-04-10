for _ in range(int(input())):
    a, b = map(int, input().split())
    print("Burenka" if (a^b) & 1 else "Tonya")