def isSquare(s):
    l = len(s)
    if l%2:
        return "NO"
    
    n = l//2
    
    for i in range(n):
        if s[i] != s[i+n]:
            return "NO"
    
    p = 0
    for i in range(n):
        if s[i] == s[i+n]:
            p += 1
        else:
            break
    
    if p == n:
        return "YES"
    
    for i in range(n-1,-1,-1):
        if s[i] == s[i+n]:
            p += 1
        else:
            break
    
    if p == n:
        return "YES"
    
    return "NO"

t = int(input())

for i in range(t):
    s = input()
    print(isSquare(s))