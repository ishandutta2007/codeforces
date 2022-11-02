a = input()
x = []
ans = -1
for i in a:
    y = x.copy()
    for t in y:
        x.append(t * 10 + int(i))
    if i != '0':
        x.append(int(i))

for i in x:
    j = int(i ** (0.5))
    if j * j == i:
        d = len(a) - len(str(i))
        if ans==-1:
            ans = d
        else:
            ans = min(ans, d)
print(ans)