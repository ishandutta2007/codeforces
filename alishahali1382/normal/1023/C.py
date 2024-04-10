n,k=map(int,input().split())
s=input()
x=0
for i in range(n):
    if i+x==k:
        print(s[:i]+")"*x)
        break
    if s[i]=="(":
        x+=1
    else:
        x-=1