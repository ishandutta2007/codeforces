n = int(input())

names = set()
used = dict()
output = []
for i in range(n):
    name = input()
    if name not in names:
        output.append("OK")
        used[name] = 1
        names.add(name)
    else:
        output.append(name + str(used[name]))
        used[name] += 1
print(*output, sep="\n")