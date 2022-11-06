s = list(input())
c = ["" for i in range(5)]
c[0] = s[0]
c[1] = s[2]
c[2] = s[4]
c[3] = s[3]
c[4] = s[1]

n = int("".join(c))
s = str((n ** 5) % 100000)
while len(s) < 5:
    s = "0" + s

print(s)