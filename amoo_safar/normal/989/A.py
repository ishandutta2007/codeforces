a= input()
fl = 0
for i in range(1,len(a)-1):
    f = a[i-1:i+2]
    #print(f)
    if ('A' in f) and ('B' in f) and ('C' in f):
        fl = 1
if fl :print('Yes')
else:print('No')