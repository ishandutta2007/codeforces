n = int(input())
for i in range(n):
    s = input().split(":")
    if(s[0] == ''): s.pop(0);
    if(s[-1] == ''): s.pop(-1);
    #print(s)
    rq = 8 - len(s) + 1;
    t = [];
    for x in s:
        if(x == ''):
            for j in range(rq): t+=['0000']
        else : t += [x]
    #print(t)
    u = "";
    for x in t: u += '0'*(4 - len(x)) + x + ':';
    print(u[:-1])