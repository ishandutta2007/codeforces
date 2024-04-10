n=int(input())
L=[input() for i in range(n)]
L.sort(key=len)
flag=True
for i in range(1,n):
    if L[i-1] not in L[i]:
        flag=False
        break
if flag:
    print("YES")
    for i in L:
        print(i)
else:
    print("NO")