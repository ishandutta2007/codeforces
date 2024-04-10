a ,b = input() ,input()
c = ["a","u","o","e","i"]
f = 0
for i in range(len(a)) :
    if i > len(a)-1 or i > len(b)-1 :
        break
    if (a[i] in c and b[i] in c) :
        f += 1
        #print("ss")
    if ( not a[i] in c and not b[i] in c) :
        f += 1
        #print("dd")
#print(len(a))
d = [len(a),len(b)]
if f == max(d):
    print("Yes")
else :
    print("No")