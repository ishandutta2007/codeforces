L=[0]*101
L[0]=L[3]=L[6]=1
for i in range(7,101):
    L[i]=L[i-3]|L[i-7]
n=int(input())
for i in range(n):
    x=int(input())
    if L[x]:
        print("YES")
    else:
        print("NO")