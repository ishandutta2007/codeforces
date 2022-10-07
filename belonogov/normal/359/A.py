n, m = map(int, input().split());
data = [[0] * m] * n;

for i in range(0, n):
    data[i] = list(map(int, input().split()));

flag = 1;
for i in range(0, n):
    if (data[i][0] == 1 or data[i][m - 1] == 1):
        flag = 0;
for i in range(0, m):
    if (data[0][i] == 1 or data[n - 1][i] == 1):
        flag = 0;

print(2 + flag * 2);