n=int(input())
s=input()
flag=True
for i in range(1,n-1):
    if s[i-1]==s[i]==s[i+1]=="0":
        flag=False
if s[:2]=="00" or s[-2:]=="00":
    flag=False
for i in range(1,n):
    if s[i-1]==s[i]=="1":
        flag=False
if s=="0":
    flag=False
if flag:
    print("Yes")
else:
    print("No")