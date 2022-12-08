import sys
range = xrange
input = sys.stdin.readline
n,k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
nesta = [n-1]*n
for i in reversed(range(n-1)):
    if A[i]==1 and A[i+1]!=1:
        nesta[i]=i
    elif A[i]==1 and A[i+1]==1:
        nesta[i]=nesta[i+1]
    else:
        nesta[i]=i+1
for i in reversed(range(n)):
    if nesta[i]==i:
        nesta[i]=i+1
cumA = [0]
for a in A:
    cumA.append(a+cumA[-1])
count = 0
for i in range(n):
    big = (cumA[-1]-cumA[i])*k
    j = i
    p = A[i]
    s = A[i]
    while j<n-1:
        if p>big:
            break
        if p==s*k:
            count += 1
        prev_j = j
        prev_s = s
        j = nesta[j]
        s = cumA[j+1]-cumA[i]
        if j-prev_j==1:
            p*=A[j]
        else:
            if p%k==0 and p//k>prev_s and p//k<s:
                count += 1
    if j==n-1 and p==s*k:
        count += 1
print(count)