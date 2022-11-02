a = input()
c = 'a'
while len(a)>0:
    if a[0] != c:
        break
    a = a.replace(c, '')
    c = chr(ord(c) + 1)
if len(a) == 0:
    print("YES")
else:
    print("NO")