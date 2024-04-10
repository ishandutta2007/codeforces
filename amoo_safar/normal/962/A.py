n = int(input())
a=list(map(int,input().split()))
s = sum(a)
s2 = 0
for i in range(n):
    s2+=a[i]
    if s2 >= s/2:
        print(i+1)
        break