s=raw_input()
a=[[s[0],1]]
for i in s[1:]:
    if(a[-1][0]==i):
        a[-1][1]+=1
    else:
        a.append([i,1])
turns=0
while((len(a)>1)):
    turns+=1
    temp=[]
    if(a[0][1]>1):
        temp.append([a[0][0],a[0][1]-1])
    for i in a[1:-1]:
        if(i[1]>2):
            temp.append([i[0],i[1]-2])
    if(a[-1][1]>1):
        temp.append([a[-1][0],a[-1][1]-1])
    if(len(temp)<2):
        break
    a=[temp[0],]
    for i in temp[1:]:
        if(i[0]!=a[-1][0]):
            a.append(i)
        else:
            a[-1][1]+=i[1]
print(turns)