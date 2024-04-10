a = input()
f =1
fl = 1
for i in a:
    if f == 0 and i == 'n':fl =0 
    if i in ['a','i','o','u','e','n']:
        f = 1
    elif f == 1:
        f = 0
    else:
        fl = 0
if fl and (a[-1] in ['a','i','o','u','e','n']):print('YES')
else :print('NO')