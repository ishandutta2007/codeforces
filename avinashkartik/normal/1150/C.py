n = int(input())
m = list(map(int,input().split()))
c1 = m.count(1)
c2 = m.count(2)
if(c2 > 0):
    print(2,end = ' ')
if(c1 > 0):
    print(1,end = ' ')
for i in range(c2-1):
    print(2,end = ' ')
for i in range(c1-1):
    print(1,end = ' ')
print()