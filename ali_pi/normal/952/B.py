import sys
i, ans = 0, 'no'
while ans == 'no':
    print(i)
    i += 1
    sys.stdout.flush()
    ans = raw_input()
if ans[:3] in ('gre', "don", 'not', 'coo') and not ans.endswith('even'):
    print('normal')
else:
    print('grumpy')