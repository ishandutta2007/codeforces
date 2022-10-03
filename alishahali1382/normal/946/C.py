s=input()
n=len(s)
orda=ord("a")
L=[ord(i)-orda for i in s]
f=True
x=0
for i in range(n):
    if x==26:
        f=False
        break
    if x>=L[i]:
        L[i]=x
        x+=1
if f and x!=26:
    print(-1)
else:
    for i in L:
        print(chr(i+orda),end="")
    print()