n,i,o = map(int,input().split())
a = list(map(int,input().split()))
f = a[0]
a.pop(0)
a.sort(reverse = True)
s = sum(a)+f
t = 0
y = i*f
#print(y/s)
while(y / s < o):
    s -= a[t]
    t+=1
print(t)