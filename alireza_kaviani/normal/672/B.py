n=int(input())
s=input()
if(len(s)>26):
    print(-1)
else:
    print(len(s)-len(set(s)))