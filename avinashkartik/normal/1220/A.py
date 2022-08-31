n = int(input())
s = input()
z = 0
o = 0
for i in s:
    if i == 'z':
        z += 1
    elif i == 'n':
        o += 1
for i in range(o):
    print(1,end = " ")
for i in range(z):
    print(0,end = " ")