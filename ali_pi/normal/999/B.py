n=input()
t=list(raw_input())
for i in range(2,n+1):
 if n%i==0:t[:i]=t[i-1::-1]
print(''.join(t))