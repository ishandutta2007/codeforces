for _ in range(int(input())):
    n=int(input())
    l=list(input().split())
    s=""
    i=0
    while(len(s)<n):
        if i<len(l):
            if s=="":
                s+=l[i]
                i+=1
            else:
                if s[-1]!=l[i][0]:
                    s+=l[i]
                    i+=1
                else:
                    s+=l[i][1]
                    i+=1
        else:
            s+=s[-1]
    print(s)