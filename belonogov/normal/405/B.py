n = int(input());
s = input();
answer = 0;
prev = -1;
t = 0;

for i in range(0, n):
    if s[i] == 'R':
        answer += i - prev - 1; 
        prev = i;
        t = 1;
    if s[i] == 'L':
        if (prev != -1):
            answer += (i - prev - 1) % 2;
        prev = i;
        t = 0;
if t == 0:
    answer += n - prev - 1;

print(answer);