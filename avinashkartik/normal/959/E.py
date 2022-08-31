n = int(input())
c = 0
for i in range(39,0,-1):
    s = pow(2,i)
    if(s <= n):
        n -= s
        c += (s//2)*i
        if(n!=0):
            c += s
print(c)