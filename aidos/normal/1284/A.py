n, m = map(int, input().split())
x = input().split()
y = input().split()
t = int(input())
for _ in range(t):
    z = int(input())-1
    print(x[z % n] + y[z % m])