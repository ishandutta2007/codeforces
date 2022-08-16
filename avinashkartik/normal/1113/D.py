s = input()
d = dict()
for i in s:
    if i in d:
        d[i] += 1
    else:
        d[i] = 1
flag = 0
if(len(set(s)) == 1):
    print("Impossible")
    flag = 1
elif(len(d) == 2):
    for i in d.values():
        if(i == 1):
            print("Impossible")
            flag =1
if(flag == 0):
    n = len(s)
    if(n%2 != 0):
        print(2)
    elif(s[:n//2] == s[n//2:]):
        t = s[:n//2]
        n1 = n//2
        while(t[:n1//2] == t[n1//2:] and n1%2 == 0):
            t = t[:n1//2]
            n1 = n1//2
        if(n1%2 == 0):
            print(1)
        else:
            print(2)
    else:
        print(1)