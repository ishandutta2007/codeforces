n,m=map(int, input().split())
out=[n]
i=n-1
m-=1
for _ in range(n-1):
    if m%2:
        out.append(i)
    else:
        out=[i]+out
    
    m//=2
    i-=1

for i in out:
    print(i, end=" ")
print()