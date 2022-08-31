n = int(input())
l = list(map(int,input().split()))
a = [0,0]
for i in range(n):
    a[l[i]%2] += i+1
#print(a)
if(a[0] > n):
    print(a[1])
else:
    print(a[0])