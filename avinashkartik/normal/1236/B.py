N = 1000000007; 
      
# Function code  
def exponentiation(bas, exp): 
    if (exp == 0): 
        return 1; 
    if (exp == 1): 
        return bas % N; 
      
    t = exponentiation(bas, int(exp / 2)); 
    t = (t * t) % N; 
      
    # if exponent is 
    # even value 
    if (exp % 2 == 0): 
        return t; 
          
    # if exponent is 
    # odd value 
    else: 
        return ((bas % N) * t) % N; 

n,m = map(int,input().split())
ct = exponentiation(2,m)-1
ct1 = exponentiation(ct,n)
print(ct1)