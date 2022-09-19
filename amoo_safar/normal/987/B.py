n,m = map(int,input().split())
if n == 1:
    if m == 1:print('=')
    else:print('<')
elif m == 1 :
    if n == 1:print('=')
    else:print('>')
elif max(n,m) < 7:
    a = n**m
    b = m**n
    if a < b:print('<')
    elif a> b:print('>')
    else:print('=')
else:
    if m < n:print('<')
    elif m > n:print('>')
    else:print('=')