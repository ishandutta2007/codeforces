n = int(input())
l = []
s = 0
for i in range(n):
    m = int(input())
    l.append([m//2,m%2])
    s += m//2

for i in range(n):
    if(s == 0):
        break
    if l[i][1] == 1:
        l[i][0] += 1
        s += 1
for i in l:
    print(i[0])