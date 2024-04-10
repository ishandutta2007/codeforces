a = input()
b = input()
s = input()
A = a.upper()
B = b.upper()
for x in s:
    c = x
    if x in a:
        c = b[a.index(x)]
    elif x in A:
        c = B[A.index(x)]
    print(c, end='')