a = input()
c = 'CODEFORCES'
if len(a)<10:print('NO')
else:
    t = 0
    for i in range(10):
        if a[i] == c[i]:t+=1
        else:break
    for i in range(10):
        if a[(-1)*(i+1)] == c[(-1)*(i+1)]:t+=1
        else:break
    print('YES' if t>=10 else 'NO')