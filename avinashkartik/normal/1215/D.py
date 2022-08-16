n = int(input())
l = list(input())
q1 = q2 = 0
for i in range(n):
    if l[i] == '?':
        l[i] = 0
        if i<n/2 :
            q1 += 1
        else : 
            q2 += 1
    else :
        l[i] = ord(l[i]) - ord('0')
s1 = sum(l[:n//2])
s2 = sum(l[n//2:])
if(q1 == q2):
    if(s1 == s2):
        print("Bicarp")
    else:
        print("Monocarp")
elif(q1 > q2):
    if( (q1-q2)//2*9 + s1 == s2 ):
        print("Bicarp")
    else:
        print("Monocarp")
else:
    if( (q2-q1)//2*9 + s2 == s1 ):
        print("Bicarp")
    else:
        print("Monocarp")