load = [int(i) for i in input().split()]
n = load[0]
k = load[1]
print(k * (6 * n - 1))
for i in range(1, n + 1):
    buff = ""
    buff += str(k * (6 * i - 5)) + ' '
    buff += str(k * (6 * i - 3)) + ' '
    buff += str(k * (6 * i - 2)) + ' '
    buff += str(k * (6 * i - 1)) + ' '
    print(buff)