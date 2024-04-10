n=input()
a=5
while a*10<=n:a*=10
print(sum(min(n-i,i) for i in range(a-1,n,a)) if n>4 else n*(n-1)//2)