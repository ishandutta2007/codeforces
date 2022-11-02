n = int(input())
a = input()
s = []
b = 0
c = 0
for i in a:
    if i == ')':
        if b > c:
            b -= 1
            s.append('1')
        else:
            s.append('0')
            c -= 1
    else:
        if b < c:
            b += 1
            s.append('1')
        else:
            s.append('0')
            c += 1
print(''.join(s))