import sys

MAX_N = 55

line = list(map(int, sys.stdin.readline().split(" ")))
studc = line[0]
roomc = line[1]

arr = list(map(int, sys.stdin.readline().split(" ")))

ncr = [[0 for i in range(MAX_N)] for j in range(MAX_N)]
ncr[0][0] = 1
for i in range(1, MAX_N):
    ncr[i][0] = 1;
    for j in range(1, MAX_N):
        ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j]

upto = [0 for i in range(MAX_N)] # upto[i] of ways to pick such that no queue exceeds i people
for i in range(1, MAX_N):
    dp = [[0 for j in range(MAX_N)] for k in range(MAX_N)]
    dp[0][0] = 1
    for j in range(roomc):
        for k in range(0, min(studc, i * arr[j]) + 1):
            for l in range(0, studc - k + 1):
                dp[j + 1][k + l] += dp[j][l] * ncr[studc - l][k]
    
    upto[i] = dp[roomc][studc]
    
ans = 0;
for i in range(1, MAX_N):
    ans += (upto[i] - upto[i - 1]) * i

print('%.12f' % (ans / (roomc ** studc)))