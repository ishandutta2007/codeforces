n = int(input())
arr = map(int, input().split())
wall = [1]
sum = [1, 0]
l = 1
for i in arr:
    if i > 0:
        wall[l-1] += 1
        sum[(l-1) % 2] += 1
    else:
        wall.append(1)
        l += 1
        sum[(l-1) % 2] += 1
ans = [0, 0]
for i in range(l):
    ans[0] += wall[i] * (sum[i%2]) - wall[i]
    ans[1] += wall[i] * (sum[(i+1)%2])
print(str(int(ans[1]/2)) + " " + str(int(ans[0]/2)))