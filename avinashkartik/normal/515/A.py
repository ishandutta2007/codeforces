a,b,s = map(int,input().split())
a = abs(a)
b = abs(b)
m = 2*min(a,b) + abs(a-b)
if(s >= m and (s-m)%2 == 0):
    print("Yes")
else:
    print("No")