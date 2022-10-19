t = int(input())
for loop in range(t):
    n = int(input())
    a = input().split()
    xoor = 0
    suum = 0
    for i in range(n):
        xoor ^= int(a[i])
        suum += int(a[i])
    print(2)
    print(str(xoor) + " " + str(suum + xoor))