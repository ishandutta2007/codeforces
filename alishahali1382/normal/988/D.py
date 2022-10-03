import sys
n=int(input())
L=sorted(list(map(int,input().split())))
dic=dict()
ss=set(L)
ans=[L[0]]
for i in range(n):
    for j in range(32):
        t=(1<<j)+L[i]
        if t in ss:
            ans=[L[i],t]
            if t+(1<<j) in ss:
                print(3)
                print(L[i],t,t+(1<<j))
                sys.exit()
print(len(ans))
for i in ans:
    print(i,end=" ")
print()