n=int(input())
s=input()
res=0
i=0
while i<n-1:
    if s[i]!=s[i+1]:
        res+=1
        i+=2
    else:
        i+=1
print(n-res)