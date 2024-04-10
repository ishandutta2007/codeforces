n = int(input())
a = list(map(int,input().split()))
fl = 0
for i in range(3,n + 1):
    if n%i == 0:
        for j in range(n//i):
            f = 1
            for k in range(j,n,n//i):
                #print(k)
                if a[k] == 0:
                    f = 0
                    break
            if f:
                fl = 1
                break
print('YES' if fl else 'NO')