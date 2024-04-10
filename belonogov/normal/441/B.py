T = 3333;
n, v = map(int, input().split());

data = [0] * T;

for i in range(0, n):
    a, b = map(int, input().split());
    data[a] += b;

answer = 0;

for i in range(1, T):
    x = v;
    tmp = min(v, data[i - 1]);
    x -= tmp;
    data[i - 1] -= tmp;
    answer += tmp;
    tmp = min(x, data[i]);
    data[i] -= tmp;
    answer += tmp;


print(answer);