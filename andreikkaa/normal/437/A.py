a = len(input()) - 2
b = len(input()) - 2
c = len(input()) - 2
d = len(input()) - 2

l = [(a, "A"), (b, "B"), (c, "C"), (d, "D")]
l.sort()

s = False

#print(l)

if l[0][0] * 2 <= l[1][0]:
    s = l[0][1]

if l[2][0] * 2 <= l[3][0]:
    if s:
        print("C")
        exit()
    s = l[3][1]

if s:
    print(s)
else:    
    print("C")