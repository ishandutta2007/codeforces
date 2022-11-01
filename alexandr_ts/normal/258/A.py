s,end = raw_input(),0
for i in range(len(s)):
    if s[i]=='0' and end ==0:
        end = 1
        print(s[:i]+s[i+1:len(s)])
if end==0:
    print(s[1:len(s)])