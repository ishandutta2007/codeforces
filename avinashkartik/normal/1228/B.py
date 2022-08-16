if(1): 
    r,c = map(int,input().split())
    a = [[0 for i in range(c)]for j in range(r)]
    R = list(map(int,input().split()))
    C = list(map(int,input().split()))
    flag = 1
    for i in range(r):
        for j in range(min(c,R[i]+1)):
            a[i][j] = 1
            #print(j,R[i])
            if(j == R[i]):
                a[i][j] = 2
    #print(a)
    for i in range(c):
        for j in range(min(r,C[i]+1)):
            if(j != C[i] and a[j][i] == 2):
                flag = 0
                break
            elif(j == C[i] and a[j][i] == 1):
                flag = 0
                break
            a[j][i] = 1
        if(flag == 0):
            break
     
    s = 0
    for i in range(r):
        for j in range(c):
            if(a[i][j] == 0):
                s += 1
     
    ans = 2
    #print(a)
    #print(s)
     
    N = 1000000007; 
     
    def expo(bas, exp): 
        if (exp == 0): 
            return 1; 
        if (exp == 1): 
            return bas % N; 
          
        t = expo(bas, int(exp / 2)); 
        t = (t * t) % N; 
          
        # if exponent is 
        # even value 
        if (exp % 2 == 0): 
            return t; 
              
        # if exponent is 
        # odd value 
        else: 
            return ((bas % N) * t) % N;
     
    ans = expo(2,s)
    if(flag == 0):
        print(0)
    else:
        print(ans)