n=input()
mp=dict()
ans=[""]*n
for i in range(n):
    s=raw_input()
    ans[i]=s
    for j in range(9):
        for k in range(j,9):
            w=s[j:k+1]
            if w in mp:
                if mp[w]!=i: mp[w]=-1
            else: mp[w]=i
for k,v in mp.iteritems():
    if v!=-1 and len(k)<len(ans[v]):
        ans[v]=k
for i in range(n):
    print ans[i]