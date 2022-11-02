

def solve():
    s = input()
    i = 0
    j = len(s)-1
    while i < len(s) and s[i] != '[':
        i += 1

    while i < len(s) and s[i] != ':':
        i += 1

    while j >= i and s[j] != ']':
        j -= 1

    while j >= i and s[j] != ':':
        j -= 1

    if i >= j:
        print(-1)
    else:
        print(s[i:j].count('|')+4)




t = 1#int(input())
for i in range(t):
    solve()