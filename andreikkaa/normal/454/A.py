n = int(input())

for i in range(1, n, 2):
    print("*" * ((n - i) // 2), "D" * i, "*" * ((n - i) // 2), sep="")

for i in range(n, 0, -2):
    print("*" * ((n - i) // 2), "D" * i, "*" * ((n - i) // 2), sep="")