s = str(raw_input())
ans = eval(s)
for i in range(len(s)):
    if s[i] == '*':
        for j in range(i + 1, len(s)):
            if s[j] == '*':
                ans = max(ans, eval(s[0:(i + 1)] + '(' + s[(i + 1):j] + ')' + s[j:len(s)]))
                
for i in range(len(s)):
    if s[i] == '*':
        ans = max(ans, eval('(' + s[0:i] + ')' + s[i:len(s)]))
        ans = max(ans, eval(s[0:(i + 1)] + '(' + s[(i + 1):len(s)] + ')'))
    
print(ans)