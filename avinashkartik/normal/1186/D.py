n = int(input())
a = []
for i in range(n):
    a.append(float(input()))
b = []
for i in a:
    b.append(i//1)
s = 0 - sum(b)
ct = 0
i = 0
while(ct < s):
    if(a[i] != b[i]):
        b[i] += 1
        ct += 1
    i += 1
for i in b:
    print(int(i))