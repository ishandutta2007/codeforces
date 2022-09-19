n,k1,k2 = map(int,input().split())
s = []
a = list(map(int,input().split()))
b = list(map(int,input().split()))
for i in range(n):
    s.append(abs(a[i]-b[i]))
for i in range(k1+k2):
    ma = s[0]
    ind = 0
    for j in range(n):
        if s[j] > ma:
            ma = s[j]
            ind = j
    if ma == 0:s[ind] = 1
    else:s[ind] -= 1
t=0
for i in s:t+=i**2
print(t)