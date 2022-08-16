n = int(input())
a = []
b = 0
for i in range(n):
    u,v = map(int,input().split())
    a.append(u-v)
    b += n*v - u
a.sort(reverse = True)
for i in range(n):
    b += a[i]*(i+1) 

print(b)