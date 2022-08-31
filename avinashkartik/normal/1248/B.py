n = int(input())
a = list(map(int,input().split()))
ne = no = 0
a.sort()
for i in range(n):
    if i<(n//2):
        ne += a[i]
    else:
        no += a[i]

print(ne*ne + no*no)