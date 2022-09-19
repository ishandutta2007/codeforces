n,k = map(int,input().split())
a = list(map(int,input().split()))
b = list(range(n))
b.sort(key = lambda e:a[e],reverse = True)
b = b[:k]
b.sort()
x =0
for i in b:x+=a[i]
b[-1] = n-1


t = -1
print(x)
for i in b:
    print(i-t,end = ' ')
    t = i