s=raw_input()
a=[0,0,0]
for i in s:
    if i=='a':
        a[2]=max(a)+1
        a[0]+=1
    else:
        a[1]=max(a[0],a[1])+1
print(max(a))