n = int(input())
a = input()
b = ''
i = 0
j = 1
while i < n:
    b += a[i]
    i += j
    j += 1
print(b)