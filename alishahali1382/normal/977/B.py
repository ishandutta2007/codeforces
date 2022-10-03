n=int(input())
s=input()
dic=dict()
for i in range(26):
    a=chr(ord("A")+i)
    for j in range(26):
        b=chr(ord("A")+j)
        dic[a+b]=0
for i in range(n-1):
    j=i+1
    dic[s[i]+s[j]]+=1
m=max(dic.values())
for i in dic:
    if dic[i]==m:
        print(i)
        break