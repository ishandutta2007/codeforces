n = int(input())
s = input()
cnt = 0
while 'xxx' in s:
    cnt += 1
    ind = s.find('xxx')
    s = s[:ind] + s[ind + 1:]
print(cnt)