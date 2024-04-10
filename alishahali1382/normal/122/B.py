s=input()
c4=s.count("4")
c7=s.count("7")
if c4==c7==0:
    print(-1)
elif c4>=c7:
    print(4)
else:
    print(7)