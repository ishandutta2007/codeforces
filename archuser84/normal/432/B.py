n = int(input())
home = []
away = []
sumH = [0]*100001
for i in range(n):
    x, y= map(int, input().split())
    home.append(x)
    away.append(y)
    sumH[x] += 1
for i in range(n):
    h=sumH[away[i]] + n - 1 - (home[i]==away[i])
    print(str(h) + " " + str(2*n-2-h))