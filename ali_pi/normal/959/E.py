n = int(raw_input())
s = n-1
for i in range(1,40):
    s += ((n-1)/(2**i))*(2**(i-1))
print s