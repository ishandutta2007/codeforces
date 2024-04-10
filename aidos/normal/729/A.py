n = int(input())
a = input()
i = 0
b = ''
while i + 2 < n:
    if a[i] + a[i+1] + a[i+2] == 'ogo':
        i += 1
        while i + 1 < n and a[i] + a[i + 1] == 'go':
            i += 2
        b += '***'
    else:
        b += a[i]
        i += 1
while i < n:
    b += a[i]
    i += 1
print(b)