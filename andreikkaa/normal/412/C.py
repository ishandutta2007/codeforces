n = int(input())

s = []
for i in range(n):
    s.append(input())

for i in range(len(s[0])):
    status = True
    letter = "a"
    m = set()
    for j in range(n):
        m.add(s[j][i])
    if "?" in m:
        m.remove("?")
    if len(m) == 0:
        print("x", end="")
    if len(m) == 1:
        for k in m:
            print(k, end="")
    if len(m) > 1:
        print("?", end="")