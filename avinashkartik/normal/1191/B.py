l = list(input().split())
for i in range(3):
    l[i] = [l[i][1],l[i][0]]
l.sort()
for i in range(3):
    l[i] = [l[i][1],l[i][0]]
#print(l)
flag = 0
if l[0] == l[1]:
    if l[1] == l[2]:
        print(0)
    else:
        print(1)
elif l[1] == l[2]:
    print(1)
elif l[0][1] == l[1][1]:
    if abs(int(l[1][0]) - int(l[0][0])) == 1:
        if l[2][1] == l[1][1]:
            if abs(int(l[2][0]) - int(l[1][0])) == 1:
                print(0)
            else:
                print(1)
        else:
            print(1)
    elif abs(int(l[1][0]) - int(l[0][0])) == 2:
        print(1)
    else:
        flag = 1
else:
    flag = 1
if flag == 1:
    if l[1][1] == l[2][1]:
        #print(int(l[2][0]) - int(l[1][0]))
        if abs(int(l[2][0]) - int(l[1][0])) <= 2:
            print(1)
        else:
            print(2)
    else:
        print(2)