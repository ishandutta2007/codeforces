a=list(map(int,input().split()))
m=0
for i in range(14):
    b = a[:]
    b[i] = 0
    s = a[i]
    f = s//14
    for j in range(14):b[j]+=f
    for j in range(1,s%14+1):
        b[(i+j)%14] += 1
    sc = 0
    for j in b:
        if j%2==0:sc+=j
    m = max(m,sc)
    #print(b)
print(m)