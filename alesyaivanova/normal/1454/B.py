t=int(input())
for p in range(t):
    n=int(input())
    array=list(map(int,input().split()))
    string=[]
    for i in array:
        string.append(i)
    ans=-1
    array.sort()
    for i in range(1,n-1):
        if array[i]!=array[i-1] and array[i]!=array[i+1]:
            ans=array[i]
            break
    if len(array)==1:
        print(1)
    elif array[0]!=array[1] :
        ans=array[0]
        for i in range(0, n):
            if string[i] == ans:
                print(i + 1)
                break
    elif array[n-1]!=array[n-2] and ans==-1:
        ans=array[n-1]
        for i in range(0, n):
            if string[i] == ans:
                print(i + 1)
                break
    elif ans==-1:
        print(-1)
    else:
        for i in range(0,n):
            if string[i]==ans:
                print(i+1)
                break