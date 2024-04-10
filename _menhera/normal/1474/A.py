N = int(input())
for i in range(N):
    input()
    x = input()
    p = 0
    for j in x:
        if(1+int(j) == p): a = 0
        else: a = 1
        p = a+int(j)
        print(a, end='')
    print()