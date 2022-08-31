s = input()
min = s[0]
l = []
for i in s:
    if(min < i):
        l.append("Ann")
    else:
        l.append("Mike")
        min = i
for i in l:
    print(i)