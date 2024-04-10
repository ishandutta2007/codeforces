n = int(input())
a = sorted([tuple(map(int,input().split())) for i in range(n)])
b = sorted([tuple(map(int,input().split())) for i in range(n)])
print(a[0][0] + b[-1][0], a[0][1] + b[-1][1])