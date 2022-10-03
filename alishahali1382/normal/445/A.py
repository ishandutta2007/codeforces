#445A
n,m=map(int,input().split())
for i in range(n):
    L=input()
    for j in range(m):
        if L[j]==".":
            if (i+j)%2==1:
                print("W",end="")
            else:
                print("B",end="")
        else:
            print("-",end="")
    print()