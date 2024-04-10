s=list(input())
t=list(input())
s.reverse()
t.reverse()
ls=len(s)
lt=len(t)
ans=ls+lt
for i in range(min(ls,lt)):
    if s[i]==t[i]:
        ans-=2
    else:
        break
print(ans)