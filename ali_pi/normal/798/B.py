l = []
for _ in range(int(raw_input())):
    s = raw_input()
    l.append({s[i:] + s[:i]: i for i in range(len(s))[::-1]})
r = min(sum(d.get(s, 9999) for d in l) for s in l[0])
print(r if r < 9999 else -1)