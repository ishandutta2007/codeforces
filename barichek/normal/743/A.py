n,a,b=map(int,input().split())
s=input()
a-=1
b-=1
print(0 if s[a]==s[b] else 1)