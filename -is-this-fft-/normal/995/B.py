n = int(input())
line = input().split(" ")
for i in range(len(line)):
    line[i] = int(line[i])

ans = 0
while len(line) != 0:
    if line[0] == line[1]:
        line.pop(0)
        line.pop(0)
    else:
        first = line.pop(0)
        idx = line.index(first)
        ans += idx
        line.pop(idx)

print(ans)