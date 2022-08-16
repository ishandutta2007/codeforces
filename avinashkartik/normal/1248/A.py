t = int(input())
for y in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    m = int(input())
    b = list(map(int,input().split()))
    ne = no = 0
    me = mo = 0
    for i in a:
        if i%2 == 0:
            ne += 1
        else:
            no +=1
    for i in b:
        if i%2 == 0:
            me += 1
        else:
            mo +=1
    print(me*ne + mo*no)