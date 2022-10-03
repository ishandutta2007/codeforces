n=int(input())
s=input()
out=0
for i in range(n-2):
    if s[i]==s[i+1]==s[i+2]=="x":
        out+=1
print(out)