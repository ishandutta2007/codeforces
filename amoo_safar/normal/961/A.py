n,m = map(int,input().split())
a = [0]*n
for i in list(map(int,input().split())):a[i-1] += 1
print(min(a))