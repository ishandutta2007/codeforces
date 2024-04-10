n = int(input())

p = [True for _ in range(n + 1)]

l = []

for i in range(2, n + 1):
    if not p[i]:
        continue
    for j in range(i, n + 1, i):
        p[j] = False
    
    a = i
    while a <= n:
        l.append(a)
        a *= i

print(len(l))
for i in l:
    print(i, end=" ")
print()