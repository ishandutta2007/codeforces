n, x = list(map(int, input().split()))

s = input()
if x <= n // 2:
    while x > 1:
        print("LEFT")
        x -= 1
    while x <= n:
        print("PRINT", s[x - 1])
        if x == n:
            exit()
        print("RIGHT")
        x += 1
else:
    while x < n:
        print("RIGHT")
        x += 1
    while x >= 1:
        print("PRINT", s[x - 1])
        if x == 1:
            exit()
        print("LEFT")
        x -= 1