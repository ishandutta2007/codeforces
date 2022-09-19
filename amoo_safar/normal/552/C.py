w,m = map(int,input().split())
o = []
while m > 0:
    o.append(m%w)
    m //= w
o.append(0)
f = 0
for i in range(len(o)-1):
    o[i+1] += o[i]//w
    o[i] %= w
    if o[i] == 0:
        continue
    if o[i] == 1:
        continue
    elif o[i] < w-1:
        f = 1
    else:
        o[i+1] += 1
print('YES' if f == 0 else 'NO')