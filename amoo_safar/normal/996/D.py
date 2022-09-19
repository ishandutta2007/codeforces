n = int(input())
a = list(map(int,input().split()))
t = 0
for i in range(n):
    x = a[0]
    a.pop(0)
    y = a.index(x)
    t+=y
    a.pop(y)
    
print(t)