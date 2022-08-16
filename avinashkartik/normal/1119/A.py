n = int(input())
a = list(map(int,input().split()))
max = 0
for i in range(n):
    if(a[i] != a[0]):
        if(i > max):
            max = i
    if(a[i] != a[-1]):
        if(n-1-i > max):
            max = n-1-i
print(max)