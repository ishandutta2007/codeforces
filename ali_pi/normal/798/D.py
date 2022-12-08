n=input()
a=sorted(zip(map(int,raw_input().split()),map(int,raw_input().split()),range(1,n+1)))
print'%d\n%d'%(n/2+1,a[n-1][2]),
for i in range(n-2,0,-2):
    print a[i][1] < a[i-1][1] and a[i-1][2] or a[i][2], 
if ~n&1:
    print(a[0][2])