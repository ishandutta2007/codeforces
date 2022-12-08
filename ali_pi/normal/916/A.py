x=input()
h,m=map(int,raw_input().split())
M,c=60*h+m,0
while'7'not in str(M//60)+str(M%60):
 c+=1;M-=x
 if M<0:M+=1440
print(c)