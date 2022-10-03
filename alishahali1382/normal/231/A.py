n=int(input())
ans=0
for i in range(n): ans+=int(sum(list(map(int, input().split())))>=2)
print(ans)