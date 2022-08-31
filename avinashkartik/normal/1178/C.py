N = 998244353
def expn(bas, exp): 
    t = 1; 
    while(exp > 0):  
        if (exp % 2 != 0): 
            t = (t * bas) % N; 
  
        bas = (bas * bas) % N; 
        exp = int(exp / 2); 
    return t % N; 

w,h = map(int,input().split())
ans = (w-1)+(h-1)
res = expn(2,ans)
print(res*4%N)