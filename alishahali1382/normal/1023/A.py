n,m=map(int,input().split())
s=input()
t=input()
def f():
    if "*" not in s:
        return s==t
    if n-1>m:
        return False
    x=s.find("*")
    return s[:x]==t[:x] and s[x+1:]==t[m-(n-1-x):]
if f():
    print("YES")
else:
    print("NO")