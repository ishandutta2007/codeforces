def C(n, m):
    res=1
    for i in range(n-m+1, n+1):
        res*=i
    for i in range(2, m+1):
        res//=i
    return res
n=int(input())
print(C(n, 5)+C(n, 6)+C(n, 7))