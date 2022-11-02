n = int(input())
a = input()
b = []
i = 0
while i < n:
    if a[i] in 'B':
        j = i
        while i < n and a[i] in 'B':
            i += 1
        b.append(i-j)
    i += 1

print(len(b))
for i in b:
    print(i, end = ' ')