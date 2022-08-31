n,k = map(int,input().split())
l = list(map(int,input().split()))
a = []
for i in range(n-1):
    a.append(l[i+1]-l[i])
sum1 = l[-1] - l[0]
a.sort(reverse = True)
sum1 -= sum(a[:k-1])
print(sum1)