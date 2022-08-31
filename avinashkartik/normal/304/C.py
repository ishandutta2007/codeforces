n = int(input())
a = [i for i in range(n)]
b = [(i+1)%n for i in range(n)]
if(n%2 == 1):
    for i in range(n):
        print(a[i],end = " ")
    print()
    for i in range(n):
        print(b[i],end = " ")
    print()
    for i in range(n):
        print((a[i]+b[i])%n,end = " ")
    print()
else:
    print(-1)