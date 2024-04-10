z = ['a', 'e', 'i', 'o', 'u', 'y']
n = int(input())
x = input()
y = ''
for i in range(n):
    if i > 0 and (y[-1] in z) and (x[i] in z):
        continue
    y = y + x[i]
print(y)