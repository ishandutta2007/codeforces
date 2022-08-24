n = int(input())
if n % 2 == 0:
    for i in range(0, n // 2):
        print(1, end = "")
else:
    print(7, end = "")
    for i in range(0, (n // 2) - 1):
        print(1, end = "")