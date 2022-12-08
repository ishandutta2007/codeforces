n=input()
a=[raw_input().strip() for i in range(n)]
a=[(z,z.count('s'),z.count('h')) for z in a]
a=sorted(a, key=lambda p: - p[1]/(p[2]+0.000001) )
s="".join( z[0] for z in a )
ans,kols=0,0
for c in s:
    if c=='s':
        kols+=1
    else:
        ans+=kols
print(ans)