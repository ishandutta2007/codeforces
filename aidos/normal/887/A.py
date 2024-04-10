s = input()
if '1' in s and s.count('0', s.index('1')) > 5:
    print('yes')
else:
    print('no')