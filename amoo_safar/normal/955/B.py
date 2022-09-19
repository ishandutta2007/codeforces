s = input()
a = [0]*26
for i in s:
    a[ord(i)-97]+=1
o = []
for i in a:
    if i > 0:o.append(i)
if len(o)==0:
    print('No')
elif len(o)>= 5:print('No')
elif len(o)==1:print('No')
elif len(o) == 4:print('Yes')
else:
    t = len(o)
    for i in o:
        if i > 1:t += 1
    if t >= 4:
        print('Yes')
    else:print('No')