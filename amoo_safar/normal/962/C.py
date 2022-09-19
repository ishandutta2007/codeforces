n = input()
a=[]
for i in range(1,int((2*10**9)**0.5)+1):
    a.append(i**2)
m = float('inf')
l = len(n)
for i in range(1,2**len(n)):
    bi = bin(i)[2:]
    bi = '0'*(l-len(bi))+bi
    ne = ''
    for i in range(l):
        if bi[i] == '1':
            ne += n[i]
    if ne[0] == '0':continue
    else:
        if int(ne) in a:
            m = min(m,bi.count('0'))
if m == float('inf'):print(-1)
else:print(m)