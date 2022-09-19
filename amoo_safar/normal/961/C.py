n = int(input())
s1 = []
for i in range(n):
    s1.append(list(map(int,input())))
input()
s2 = []
for i in range(n):
    s2.append(list(map(int,input())))
input()
s3 = []
for i in range(n):
    s3.append(list(map(int,input())))
input()
s4 = []
for i in range(n):
    s4.append(list(map(int,input())))
a = [s1,s2,s3,s4]
b = [0,1,2,3]
m = float('inf')
for i in range(4):
    b = [0,1,2,3]
    f = []
    f.append(b[i])
    b.pop(i)
    
    for j in range(3):
        d= b[:]
        f.append(d[j])
        d.pop(j)
        for k in range(2):
            e= d[:]
            #print(e)
            f.append(e[k])
            e.pop(k)
            f.append(e[0])


            se = []
            for v in f:se.append(a[v])
            fa = 0
            if n%2==0:
                for seg in se:
                    for ii in range(n):
                        for jj in range(n):
                            if (ii+jj)%2 != seg[ii][jj]:
                                fa += 1
                m = min(m,fa,4*n*n-fa)
                #print(fa)
            else:
                for seg in se[:2]:
                    for ii in range(n):
                        for jj in range(n):
                            if (ii+jj)%2 != seg[ii][jj]:
                                fa += 1
                for seg in se[2:]:
                    for ii in range(n):
                        for jj in range(n):
                            if (ii+jj)%2 == seg[ii][jj]:
                                fa += 1
             #   print(fa)
                m = min(m,fa,4*n*n-fa)
            #print(m,f)
            f.pop()
            f.pop()
        f.pop()
    f.pop()
print(m)