for _ in range(int(input())):
    x,y,a,b = map(int,input().split())
    print(int((y-x)/(a+b)) if (y-x)%(a+b)==0 else '-1')