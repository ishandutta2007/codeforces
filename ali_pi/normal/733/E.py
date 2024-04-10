n=int(raw_input())
string =raw_input()
q1,q2,B,C=[],[],[],[]
A=0
for i in range(n):
    if string[i] == "D":
        q1.append(i)
    else:
        q2.append(n-1-i)

for i in range(len(q1)):
    A+=(q1[i]-i)*2+1
    B.append(A)

A=0
temp = []
for i in range(len(q2)):
    A+=(q2[len(q2)-1-i]-i)*2+1
    C.append(A)
C.reverse()

B=list(map(str,B+C))
print(" ".join(B))