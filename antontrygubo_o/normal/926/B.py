def f(a, b):
    while a and b:
        if (a<b):
            b = b%a
        else :
            a = a%b
    return a+b;
    

    
n = int(input())

List = []
for i in range(n):
    List.append(0)

i = 0
for s in input().split(' '):
     List[i] = int(s)
     i = i+1
    
List.sort()
if not (n-1):
    print(0)
else:
    kek = List[1]-List[0]
    for i in range(n-2):
        kek = f(kek, List[i+2]-List[i+1])
    ans = ((List[n-1]-List[0])/kek + 1 - n)
    print(int(ans))