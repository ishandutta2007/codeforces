n,l,r = map(int,input().split())
low = pow(2,l-1)
high = pow(2,r-1)
sl = low*2 - 1 + (n-l)
sh = high*2 - 1 + (n-r)*high
print(sl,sh)