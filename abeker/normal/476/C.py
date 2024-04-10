load = [int(i) for i in input().split()]
a = load[0]
b = load[1]
print(b * (b - 1) // 2 * (b * a * (a + 1) // 2 + a) % 1000000007)