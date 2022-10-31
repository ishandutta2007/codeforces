n = int(raw_input())
x = raw_input()
ans = 0
for i in xrange(n):
    y, z = raw_input().strip().split('->')
    if y == x or z == x:
        ans = 1 - ans

if ans:
    print 'contest'
else:
    print 'home'