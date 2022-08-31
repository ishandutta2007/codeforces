n,k = map(int,input().split())
a = list(map(int,input().split()))
m,k1 = map(int,input().split())
b = list(map(int,input().split()))
a = a[::-1]
b = b[::-1]
s1 = 0
for i in range(n):
    s1 += pow(k,i)*a[i]
s2 = 0
for i in range(m):
    s2 += pow(k1,i)*b[i]
if s1 > s2:
    print(">")
elif s1 < s2:
    print("<")
else:
    print("=")