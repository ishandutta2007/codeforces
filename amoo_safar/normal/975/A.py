n = int(input())
a = list(input().split())
b = []
al = 'abcdefghijklmnopqrstuvwxyz'
for i in a:
    c = [0]*26
    for j in i:
        c[97-ord(j)]=1
    r = ''
    for j in range(26):
        if c[j] == 1:r+=al[j]
    b.append(r)
print(len(set(b)))