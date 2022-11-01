s = raw_input()
ar = [0] * 26
for i in range(len(s)):
    ar[(ord(s[i]) - ord('a'))] = 1
if sum(ar) % 2 == 0:
    print('CHAT WITH HER!')
else:
    print('IGNORE HIM!')