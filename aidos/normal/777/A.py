n = int(input())
x = int(input())

n %= 6
for i in range(n, 0, -1):
    if i % 2 == 0 and (x == 1 or x == 2):
        x = 3 - x
    elif i % 2 == 1 and (x == 1 or x == 0):
        x = 1 - x
print(x)