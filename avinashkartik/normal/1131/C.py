n = int(input())
l = list(map(int,input().split()))
l.sort()
ans = [0 for i in range(n)]
if(n%2 == 0):
    mid2 = n//2
    mid1 = mid2 - 1
    ans[mid1] = l[-1]
    ans[mid2] = l[-2]
    j = 1
    for i in range(n-3,-1,-2):
        #print(i,j)
        ans[mid1-j] = l[i]
        ans[mid2+j] = l[i-1]
        j += 1
else:
    mid1 = n//2
    ans[mid1] = l[-1]
    j = 1
    for i in range(n-2,-1,-2):
        ans[mid1-j] = l[i]
        ans[mid1+j] = l[i-1]
        j += 1
for i in ans:
    print(i,end = ' ')