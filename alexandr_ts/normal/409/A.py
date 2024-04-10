s1 = raw_input()
s2 = raw_input()
i = 0
a = 0
b = 0
while(i < len(s1)):
    if(s1[i] == '8' and s1[i + 1] == '<'):
        if(s2[i] == '8' and s2[i + 1] == '<'):
            a += 0
        elif(s2[i] == '[' and s2[i + 1] == ']'):
            a += 1
        else:
            a -= 1
    elif(s1[i] == '[' and s1[i + 1] == ']'):
        if(s2[i] == '8' and s2[i + 1] == '<'):
            a -= 1
        elif(s2[i] == '(' and s2[i + 1] == ')'):
            a += 1
    elif(s1[i] == '(' and s1[i + 1] == ')'):
        if(s2[i] == '(' and s2[i + 1] == ')'):
            a += 0
        elif(s2[i] == '[' and s2[i + 1] == ']'):
            a -= 1
        else:
            a += 1
    i += 2
   

if(a == 0):
    print "TIE"
if(a < 0):
    print "TEAM 2 WINS"
elif(a > 0):
    print "TEAM 1 WINS"