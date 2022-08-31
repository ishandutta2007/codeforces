n = int(input())
d = str(n)
a = []
t = n
if(n<10):
    print(n)
else:
    flag = 0
    while(n>9):
        a.append(9)
        t = n%10
        if(t != 9):
            flag = 1
        n //= 10
    s = n
    #print(s,t,flag)
    a.append(n-1)
    if(a[-1] != 0):
        a1 = 1
        a2 = 1
        if(flag == 0 or len(d)<3):
            for i in range(1,s+1):
                for j in range(1,10):
                    if((i==s and j<=t) or (i<s)):
                        if(i*j > a1*a2):
                            a1 = i
                            a2 = j
        else:
            for i in range(1,s+1):
                for j in range(1,10):
                    if((i==s and j<t) or (i<s)):
                        if(i*j > a1*a2):
                            a1 = i
                            a2 = j   
        #print(a1,a2)
        a[-1] = a1
        a[-2] = a2
    else:
        a[-1] = 1
    ans = 1
    if(len(d)>2):
        if(a[-3] == 9 and a[-2] == 7 and d[1] >= '8' and d[2] >= '8'):
            a[-2] = 8
            a[-3] = 8
        elif(a[-3] == 9 and a[-2] == 6 and d[1] >= '7' and d[2] >= '8'):
            a[-2] = 7
            a[-3] = 8
        elif(a[-3] == 9 and a[-2] == 5 and d[1] >= '6' and d[2] >= '8'):
            a[-2] = 6
            a[-3] = 8
        elif(a[-3] == 9 and a[-2] == 4 and d[1] >= '5' and d[2] >= '8'):
            a[-2] = 5
            a[-3] = 8
        elif(a[-3] == 9 and a[-2] == 3 and d[1] >= '4' and d[2] >= '8'):
            a[-2] = 4
            a[-3] = 8
        elif(a[-3] == 9 and a[-2] == 2 and d[1] >= '3' and d[2] >= '8'):
            a[-2] = 3
            a[-3] = 8
        elif(a[-3] == 9 and a[-2] == 1 and d[1] >= '2' and d[2] >= '8'):
            a[-2] = 2
            a[-3] = 8
    #print(a)
    for i in a:
        ans *= i
    print(ans)