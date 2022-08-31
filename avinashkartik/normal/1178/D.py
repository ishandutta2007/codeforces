prime = [1 for i in range(2001)] 
def SieveOfEratosthenes(n):
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p * p, n+1, p): 
                prime[i] = 0
        p += 1


n = int(input())
if n < 3:
    print(-1)
else:
    SieveOfEratosthenes(2000)
    la = n
    for i in range(n,2001):
        if prime[i] == 1:
            la = i
            break
    print(la)
    for i in range(n-1):     
        print(i+1,i+2)
    print(n,1)
    for i in range(la-n):
        print(i+1,i+1+n//2)