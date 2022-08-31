n,k = map(int,input().split())
l = list(input())
a = [0 for i in range(26)]
i = 0
while(i < n-k+1):
    c = l[i]
    for j in range(i,i+k):
        if(l[j] != c):
            i = j
            break
    else:
        a[ord(c)-ord('a')] += 1
        i += k
print(max(a))