r = list(range(1,input() + 1))
print(3 * len(r) // 2)
for i in r[1::2] + r[::2] + r[1::2]: print(i)