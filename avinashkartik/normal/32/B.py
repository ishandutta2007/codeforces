n = list(input())
l = len(n)
i = 0
while(i<l):
    if(n[i] == '.'):
        print(0,end = "")
        i += 1
    elif(n[i+1] == '.'):
        print(1,end = "")
        i += 2
    else:
        print(2,end = "")
        i += 2
print()