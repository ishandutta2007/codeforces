n=int(input())
dic=dict()
L=[]
X=[]
t00=0
for i in range(n):
    s=input()
    q=0
    f1=True
    f2=True
    for j in s:
        if j=="(":
            q+=1
        else:
            q-=1
        if q<0:
            f1=False
    q=0
    for j in s[::-1]:
        if j=="(":
            q+=1
        else:
            q-=1
        if q>0:
            f2=False

    dic[q]=dic[-q]=0
    if f1:
        X.append(q)
    if f2:
        L.append(q)

for i in L:
    dic[i]+=1

out=0
for i in X:
    out+=dic[-i]
print(out)