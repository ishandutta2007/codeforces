d,s = map(int,input().split())
m1 = m2 = 0
a = []
ans = []
for y in range(d):
    l,r = map(int,input().split())
    m1 += l
    ans.append(l)
    m2 += r
    a.append([l,r])
if m1 <= s <= m2:
    print("YES")
    s -= m1
    for i in range(d):
        if s == 0:
            break
        u = a[i][1] - a[i][0]
        if u > s:
            ans[i] += s
            s = 0
        else:
            ans[i] += u
            s -= u
    for i in ans:
        print(i,end = " ")
else:
    print("NO")