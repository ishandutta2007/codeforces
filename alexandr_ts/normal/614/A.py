s = raw_input().split()
l = int(s[0])
r = int(s[1])
k = int(s[2])
cur = 1
printedd = False

if (l <= 1 and 1 <= r):
    print(1)
    printedd = True

while (cur <= r):
    cur *= k
    if (l <= cur and cur <= r):
        print(cur)
        printedd = True
if not printedd:
    print(-1)