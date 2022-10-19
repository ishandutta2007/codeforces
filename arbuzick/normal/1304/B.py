n, m =map(int, input().split())
a = [""]*n
for i in range(n):
    a[i] = input()
s = ""
z = ""
p = set()
for i in range(n):
    for j in range(i, n):
        if i != j and i not in p and j not in p:
            if a[i] == a[j][::-1]:
                s += a[i]
                p.add(i)
                p.add(j)
for i in range(n):
    if i not in p and a[i] == a[i][::-1]:
        z = a[i]
        break
print(len(s)*2+len(z))
print(s+z+s[::-1])