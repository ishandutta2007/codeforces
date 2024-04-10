s=raw_input().split()
n=int(s[0])
m=int(s[1])
k=int(s[2])
a=list(map(int, raw_input().split()))
a.sort(reverse=True)
for i in range(n):
    a[i]-=1
i,qua=0,0    
while k<m:
    if i>=n:
        k=m+1
        qua=-1  
    else:    
        k+=a[i]
        qua+=1
        i+=1
    
print(qua)