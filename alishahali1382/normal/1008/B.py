n=int(input())
L=[]
for i in range(n):
    L.append(sorted(list(map(int,input().split()))))

def check():
    m=L[0][1]
    for i in range(1,n):
        if L[i][1]<=m:
            m=L[i][1]
        elif L[i][0]<=m:
            m=L[i][0]
        else:
            return False
    return True

if check():
    print("YES")
else:
    print("NO")