t = int(input())
mod = pow(10,9) + 7
for y in range(t):
    n,m = map(int,input().split())
    u = n//m
    v = m%10
    c = 0
    if(n < m):
    	print(0)
    else:
        if v == 0:
    	    c = 0
        elif m % 2 == 0:
            c = (40*(u//10))
        elif(v == 5):
            c = (25*(u//10))
        else:
            c = (45*(u//10))
	    #print(c)
        for i in range(u%10):
            c += (v*(i+1))%10
        print(c)