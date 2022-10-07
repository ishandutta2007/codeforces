n = int(input());

s = [['.'] * n] * n;

for i in range(0, n):
    s[i] = list(input());

flag = 1;

for i in range(0, n - 2):
    for j in range(1, n - 1):
        if (s[i][j] == '#'):
            flag &= s[i + 1][j] == '#';
            flag &= s[i + 1][j - 1] == '#';
            flag &= s[i + 1][j + 1] == '#';
            flag &= s[i + 2][j] == '#';
            flag &= s[i][j] == '#';
            s[i + 1][j] = '.';
            s[i + 1][j - 1] = '.';
            s[i + 1][j + 1] = '.';
            s[i + 2][j] = '.';
            s[i][j] = '.';

for i in range(0, n):
    for j in range(0, n):
        flag &= s[i][j] == '.';



if (flag == 1):
    print("YES");
else:
    print("NO");