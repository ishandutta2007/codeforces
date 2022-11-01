n=int(input())
l=[]
for i in range(n):
    a=input()
    if len(a)>10:
        l.append(a[0]+str(len(a)-2)+a[-1])
    else:
        l.append(a)
for i in range(n):
    print(l[i])