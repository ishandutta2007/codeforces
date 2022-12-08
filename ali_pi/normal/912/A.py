R=lambda:map(int,raw_input().split())
a,b=R()
x,y,z=R()
print(max(0,2*x+y-a)+max(0,y+3*z-b))