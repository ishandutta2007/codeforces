s,v1,v2,t1,t2=map(int,input().split())
a=s*v1+t1*2
b=s*v2+t2*2
if a==b:
    print("Friendship")
elif a<b:
    print("First")
else:
    print("Second")