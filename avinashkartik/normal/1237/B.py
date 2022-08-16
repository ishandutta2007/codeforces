n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
l = [0 for i in range(n+1)]
flag = [0 for i in range(n+1)]
for i in range(n):
    l[a[i]] = i
ct = 0
z = 0
for i in range(n):
    if flag[a[i]] != 1:
        for j in range(z,n):
            #print(b[j],a[i])
            if b[j] != a[i]:
                ct += 1
                flag[b[j]] = 1
            else:
                z = j+1
                break
print(ct)