a = input()
b = input()
d = [0] * 10
n = 0
for j in range(1000100):
    t = str(j)
    if len(t) + j == len(a):
        n = j
for x in str(n):
    d[ord(x) - ord('0')] -= 1
for x in a:
    d[ord(x) - ord('0')] += 1
for x in b:
    d[ord(x) - ord('0')] -= 1
if sum(d)==0:
    print(b)
else:
    A = []
    B = []
    C = []
    D = []
    if b[0] != '0':
        A = list(b)
        for j in range(10):
            for k in range(d[j]):
                A.append(chr(ord('0') + j))
    t = 1
    while t < len(d) and d[t] == 0:
        t += 1
    oo = ord('0')
    if t < len(d):
        B.append(chr(oo+t))
        d[t] -= 1
        for j in range(ord(b[0]) - oo):
            for k in range(d[j]):
                B.append(chr(ord('0') + j))
        B.extend(list(b))
        for j in range(ord(b[0]) - oo, 10):
            for k in range(d[j]):
                B.append(chr(ord('0') + j))
        
        
        C.append(chr(oo+t))
        for j in range(min(ord(b[0]) - oo+1, 10)):
            for k in range(d[j]):
                C.append(chr(ord('0') + j))
        C.extend(list(b))
        for j in range(ord(b[0]) - oo+1, 10):
            for k in range(d[j]):
                C.append(chr(ord('0') + j))
        
    ans = []
    if len(A) > 0:
        ans.append(''.join(A))
    
    if len(B) > 0:
        ans.append(''.join(B))
    
    if len(C) > 0:
        ans.append(''.join(C))
    
    print(min(ans))