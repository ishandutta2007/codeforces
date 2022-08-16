n = int(input())
l = list(map(int,input().split()))
p = l[-1]
for i in range(n-1,-1,-1):
    if(l[i] != p):
        print(i+1)
        break