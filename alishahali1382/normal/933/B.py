a,b=map(int,input().split())
c=-(a//b)
out=[a%b]
while True:
    #print(c)
    out.append(c%b)
    c=-(c//b)
    if out[-1]==c==0:
        break
print(len(out)-1)
for i in out[:-1]:
    print(i,end=" ")
print()