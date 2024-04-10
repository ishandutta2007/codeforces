n=int(input())
name=[]
for i in range(n):
    x=input()
    name.append(x+(101-len(x))*"{")

G=[[] for i in range(26)]  #out
G2=[[] for i in range(26)] #in

def f(s):
    return ord(s)-ord("a")

flag=True

for i in range(1,n):
    for j in range(100):
        if name[i][j]!=name[i-1][j]:
            if "{"==name[i][j]:
                flag=False
                break
            elif "{"==name[i-1][j]:
                break
            G[f(name[i-1][j])].append(f(name[i][j]))
            G2[f(name[i][j])].append(f(name[i-1][j]))
            break

L=[]
S=[]
for i in range(26):
    if G2[i]==[]:
        S.append(i)
#print(S)
while S!=[]:
    node=S.pop(0)
    L.append(node)
    for i in G[node]:
        G2[i].remove(node)
        if G2[i]==[]:
            S.append(i)
if G2==[[] for i in range(26)] and len(L)==26 and flag:
    for i in L:
        print(chr(ord("a")+i),end="")
    print()
else:
    print("Impossible")