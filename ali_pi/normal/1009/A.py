R=lambda:map(int,raw_input().split())[::-1]
R()
a=R()
b=R()
c=0
while a and b:
    if b[-1]>=a[-1]:
        b.pop()
        c+=1
    a.pop()
print(c)