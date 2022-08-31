n,m = map(int,input().split())
l = list(map(int,input().split()))
a = [0 for i in range(101)]
ans = []
for i in range(n):
    if i == 0:
        a[l[i]] += 1
        ans.append(0)
    else:
        s = 0
        t = m - l[i]
        count = 0
        for j in range(1,101):
            if(a[j]*j < t-s):
                s += a[j]*j
                count += a[j]
            else:
                u = (t-s)//j
                #print(count,u)
                ans.append(i-count-u)
                break
        else:
            ans.append(0)
        a[l[i]] += 1

    #print(a)
for i in ans:
    print(i,end = " ")