from sys import stdin, stdout
n = int(stdin.readline())
s = stdin.readline().strip()
mins = []
packs = []

for i in range(len(s)):
    if s[i] == '*':
        mins.append(i)
    elif s[i] == 'P':
        packs.append(i)

l, r = -1, 2 * len(s) + 1
while r - l > 1:
    m = (l + r) >> 1
    
    test1 = mins[:]
    test2 = packs[:]
    
    
    while test2 and test1:
        cnt = m
        pos = test2.pop()
        
        if pos > test1[-1]:
            while test1 and abs(pos - test1[-1]) <= cnt:
                cnt -= abs(pos - test1[-1])
                pos = test1[-1]
                test1.pop()
        else:
            cntl, cntr = 0, 0
            
            if abs(test1[-1] - pos) > m:
                break
            
            lpos = (m + pos - test1[-1]) // 2
            rpos = m - 2 * abs(test1[-1] - pos)
            
            lb, rb = -1, len(test1)
            while rb - lb > 1:
                mb = (lb + rb) >> 1
                
                if pos - test1[mb] <= lpos:
                    rb = mb
                else:
                    lb = mb
            
            cntl = len(test1) - rb
            
            lb, rb = -1, len(test1)
            while rb - lb > 1:
                mb = (lb + rb) >> 1
                
                if pos - test1[mb] <= rpos:
                    rb = mb
                else:
                    lb = mb
            cntr = len(test1) - rb
            cnt = max(cntl, cntr)
            while test1 and cnt:
                test1.pop()
                cnt -= 1
    if not test1:
        r = m
    else:
        l = m
stdout.write(str(r))