import math;


T = 5005;
n = int(input())

a = [0] * T;
b = map(int, input().split());

for x in b:
    a[x] += 1;


flag = 0;
answer = 0;
ans = [];
for i in range(T - 1, 0, -1):
    #print("here")
    if a[i] > 0:
        if flag == 0:
            answer += 1
            flag = 1
            ans = [i];
        else:
            if a[i] == 1:
                ans = ans + [i];
            else:
                ans = [i] + ans + [i];

print(len(ans))
print(' '.join(map(str, ans)));

#print("hello")