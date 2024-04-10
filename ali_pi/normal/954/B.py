n=input()
x=0
s=raw_input()
for i in range(1,n//2+1):
    if s[:i]==s[i:i*2]: x=i
print(n-max(x-1,0))