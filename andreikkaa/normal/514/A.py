a = input()
b = ""
i = 0
if a[i] == '9':
    b += a[i]
    i += 1

while i < len(a):
    b += str(min(int(a[i]), 9 - int(a[i])))
    i += 1

print(b)