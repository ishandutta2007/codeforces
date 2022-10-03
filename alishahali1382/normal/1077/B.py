n=int(input())
'''
s=input().replace(" ", "")
s="0"+s[1:-1]+"0"
'''
A=list(map(int, input().split()))
B=[A[i] for i in range(n)]
ans=0
for i in range(n-2):
    if A[i:i+3]==[1, 0, 1]:
        A[i+2]=0
        ans+=1
out=ans
A=[B[i] for i in range(n)]
ans=0
for i in range(n-3, -1, -1):
    if A[i:i+3]==[1, 0, 1]:
        A[i]=0
        ans+=1
out=min(out, ans)
print(ans)


'''
A=[1]
l=0
for i in [0]+list(map(int, input().split()))+[0]:
    if (l==i):
        A[-1]+=1
    else:
        A.append(1)
        l=1-l
ans=0
for i in range(2, len(A)-1, 2):
    print(A[i])
    if (A[i]>1):
        continue
    
    ans+=1
print(ans)
'''