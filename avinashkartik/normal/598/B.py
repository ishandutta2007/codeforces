a = list(input())
n = len(a)
t = int(input())
for y in range(t):
    l,r,k = map(int,input().split())
    new = [0 for i in range(n)]
    for i in range(l-1):
        new[i] = a[i]
    if r!= l:
        k %= r-l+1
        st = r-1-k
        for i in range(r-1,l-2,-1):
            new[i] = a[st]
            st -= 1
            if(st<l-1):
                st = r-1
        for i in range(r,n):
            new[i] = a[i]
        a = new
    #print(a)
print(''.join(a))