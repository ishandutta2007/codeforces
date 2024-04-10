s = input()
d = set()
for i in range(ord('a'), ord('z') + 1):
    for j in range(len(s)+1):
        d.add(s[:j] + chr(i) + s[j:])
print(len(d))