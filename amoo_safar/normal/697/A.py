t,s,x = map(int,input().split())
if (x == t+1) or (x<t) :print('NO')
elif ((x - t) % s == 0) or ((x - t - 1) % s == 0):print('YES')
else:print('NO')