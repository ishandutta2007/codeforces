import sys
def dfs(node,color):
    ans=0
    if (color!=c[node]):
        color=c[node]
        ans+=1
	
    for i in child[node]:
        ans+=dfs(i,color)
    return ans

sys.setrecursionlimit(10002)

n=int(input())
parent=[0]+list(map(int,input().split()))
c=list(map(int,input().split()))
child=[[]for i in range(n)]

for i in range(1,n):
    child[parent[i]-1].append(i)

print(dfs(0,0))