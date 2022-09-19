n,s1,s2 = (map(int,input().split()))
a = input()
p = 0
f = 0
for i in range(n):
    if a[i] == '*':
        f = 0
        continue
    if s1 == 0 and f == 2:
        f = 0
        continue
    if s2==0 and f == 1:
        f = 0
        continue
    if f == 0 and (s1+s2) == 0:
        continue
    if f == 2:
        s1 -= 1
        p+=1
        f = 1
    elif f == 1:
        s2 -= 1
        p+=1
        f = 2
    elif f == 0:
        if s1>s2:
            s1 -= 1
            p+=1
            f = 1
        else:
            s2-=1
            p+=1
            f= 2
            
print(p)