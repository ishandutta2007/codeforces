n = int(input())
a = list(map(int, input().split()))
b = dict()
for x in a:
    b[x] = b.get(x, 0) + 1
A = dict()
B = dict()
cnta = 0
cntb = 0
for k, v in b.items():
    if v == 1:
        if cnta > cntb:
            cntb += 1
            B[k] = 1
        else:
            cnta += 1
            A[k] = 1

for k, v in b.items():
    if v == 2:
        A[k] = 2
    elif v > 1:
        if cnta > cntb:
            A[k] = v-1
            B[k] = 1
            cntb+=1
        else:
            A[k] = v
if cnta==cntb:
    print('YES')
    for i in a:
        if A.get(i, 0) > 0:
            A[i] = A.get(i, 0) - 1
            print('A', end='')
        else:
            B[i] = B.get(i, 0) - 1
            print('B', end='')
else:
    print('NO')