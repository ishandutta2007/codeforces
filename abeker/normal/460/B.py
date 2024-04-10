load = [int(i) for i in input().split()]

def digit_sum(x):
    res = 0
    while x > 0:
        res += x % 10
        x //= 10
    return res

a = load[0]
b = load[1]
c = load[2]

sol = []

for i in range(1, 90):
    tmp = b * i ** a + c
    if (i == digit_sum(tmp) and tmp < 10 ** 9):
        sol.append(tmp)

print(len(sol))

buff = ""
for i in range(len(sol)):
    buff += str(sol[i]) + ' '
print(buff)