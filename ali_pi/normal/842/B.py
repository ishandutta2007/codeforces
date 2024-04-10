R=lambda:map(int,raw_input().split())
r,d=R()
a=0
for _ in range(input()):
 x,y,z=R()
 if(r-d+z)**2<=x*x+y*y<=(r-z)**2:a+=1
print a