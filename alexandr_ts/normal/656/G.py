s = input().split()
f, i, t = int(s[0]), int(s[1]), int(s[2])
x = [""] *f
for p in range(f):
    x[p]=input()
kitten = 0
for i2 in range(i):
    cnt = 0
    for p in range(f):
        if x[p][i2] == 'Y':
            cnt+=1
    if cnt>=t:
        kitten += 1
print(kitten)