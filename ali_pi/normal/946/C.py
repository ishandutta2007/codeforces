s = raw_input()
t = 97
o = ''
for i in s:
    if ord(i)<= t and t <= 122:
        o += chr(t)
        t += 1
    else:
        o += i
if t != 123:print(-1)
else:print(o)