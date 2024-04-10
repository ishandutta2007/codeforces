n,p,w,d=map(int,input().split())
y=0
while y<w and p%w:y+=1;p-=d
z=n-p//w-y
print(*((p//w,y,z),[-1])[y==w or p|z<0])