n=int(raw_input())
x=map(int,raw_input().split())
y=map(int,raw_input().split())

cnt=0
ans1=[]
ans2=[]
bit=dict()
for i in range(30,-1,-1):
    for j in range(0,n):
        if x[j]&1<<i > 0 and x[j] < 1<<i+1:
            if i not in bit:
                bit[i] = j
            else:
                x[j] ^= x[bit[i]]
                ans1.append((j,bit[i]))
can = 1
for i in range(30,-1,-1):
    has = 0 
    for j in range(0,n):
        if y[j]&1<<i > 0 and y[j] < 1<<i+1:
            has = 1
            if i not in bit:
                can = 0
            else:
                if j == bit[i]:
                    continue
                elif y[bit[i]]&1<<i == 0:
                    y[j],y[bit[i]] = y[bit[i]],y[j]
                    ans2.append((j,bit[i]))
                    ans2.append((bit[i],j))
                    ans2.append((j,bit[i]))
                else:
                    y[j] ^= y[bit[i]]
                    ans2.append((j,bit[i]))
    if not can:
        break
    if has:
        for k in range(i,-1,-1):
            p1 = x[bit[i]]&1<<k
            p2 = y[bit[i]]&1<<k
            if p1 == p2:
                continue
            else:
                if k not in bit:
                    can = 0;
                    break
                else:
                    x[bit[i]] ^= x[bit[k]]
                    ans1.append((bit[i],bit[k]))
if not can:
    print -1
else:
    for j in range(0,n):
        if x[j] != y[j]:
            ans1.append((j,j))
    print len(ans1)+len(ans2)
    for j in range(0, len(ans1)):
        print ans1[j][0]+1,ans1[j][1]+1
    for j in range(len(ans2)-1, -1, -1):
        print ans2[j][0]+1,ans2[j][1]+1