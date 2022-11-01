s = input()
t = 'CODEFORCES'
for i in range(len(s)):
    if (s[0:i] == t):
        print('YES')
        exit()        
    for j in range(i + 1, len(s)):
        if (s[0:i] + s[j:len(s)] == t or s[j:len(s)] == t):
            print('YES')
            exit()
print('NO')