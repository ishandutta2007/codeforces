#n=int(input())
#L=list(map(int,input().split()))
s=input()
n=len(s)
L=""
for i in range(n):
    if s[i] in "aeoui":
        L+="0"
    elif s[i]=="n":
        L+="2"
    else:
        L+="1"
f=True
if L[-1]=="1":
    f=False
for i in range(n-1):
    if s[i]=="1" and s[i+1]!="0":
        f=False
f=f and not ("11" in L or "12" in L)
if f:
    print("YES")
else:
    print("NO")