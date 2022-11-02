s, k = input().split()
k = int(k)
if s == '0':
    print(0)
elif s.count('0') < k:
    print(len(s) - 1)
else:
    s = s[::-1]
    cnt = 0
    for x in s:
        if k == 0:
            break
        if x == '0':
            k -= 1
        else:
            cnt += 1
    print(cnt)