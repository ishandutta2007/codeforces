a,b=map(int,raw_input().split())
the=1
for i in range(a+1,min(b,a+10)+1):
 the*=i
print(the%10)