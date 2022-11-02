f= open("output.txt","w+")
I=open("input.txt", "r")
n = int(I.readline())
a = list(map(int, I.readline().split()))
b = [0] * n
cc = 0
for i in range(n-1, -1, -1):
    if a[i] <= 0:
        cc += 1
    b[i] = cc
cc = 0
ans=n+1
for i in range(0, n-1):
    if a[i] >= 0:
        cc += 1
    ans = min(ans, cc + b[i+1])
f.write(str(ans))