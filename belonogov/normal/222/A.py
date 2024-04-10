n, k = map(int, input().split());

a = list(map(int, input().split()));

flag = 1
for i in range(k, n):
    flag &= a[k - 1] == a[i];
if (flag == 0):
    print(-1);
else:
    cur = k - 1;
    while (cur >= 0 and a[cur] == a[k - 1]):
        cur -= 1;
    print(cur + 1);