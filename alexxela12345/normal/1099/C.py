s = input()
k = int(input())
n = len(s)
min_len = 0
any_snowflake = False
max_len = 0
for i in range(n):
    if s[i] == '?':
        min_len -= 1
    elif s[i] == '*':
        min_len -= 1
        any_snowflake = True
    else:
        min_len += 1
        max_len += 1
if min_len > k:
    print('Impossible')
elif max_len < k and any_snowflake == False:
    print('Impossible')
else:
    need_more = k - min_len
    new_s = ""
    for i in range(n):
        if s[i] == '?':
            if need_more == 0:
                new_s = new_s[:-1]
            else:
                need_more -= 1
        elif s[i] == '*':
            if need_more == 0:
                new_s = new_s[:-1]
            else:
                new_s += new_s[-1] * (need_more - 1)
                need_more = 0
        else:
            new_s += s[i]
    print(new_s)