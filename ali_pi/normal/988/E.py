y =raw_input()
fives = (y.count('5'))
zeroes = (y.count('0'))
twos = (y.count('2'))
sevens = (y.count('7'))
if fives == 0:
    if zeroes < 2:
        print(-1)
        exit(0)
else:
    if zeroes == 0 and twos == 0 and sevens == 0:
        print(-1)
        exit(0)
best = 5 * len(y)
y = y[::-1]
for xx in [['5','2'], ['0','0'], ['5','7'], ['0','5'] ]:
    z = y
    count = 0
    for x in xx:        
        if not x in z:
            count = 5 * len(y)
            break
        f = z.index(x)
        z = z[:f] + z[f+1:]        
        count += f
    if len(z) > 2 and z[-1] == '0':
        valid = False 
        for x in z[::-1]:
            if x == '0':
                count += 1
                continue
            else:
                valid = True
                break
        if not valid:
            count += 5 * len(y)

    if count < best:
        best = count
print(best)