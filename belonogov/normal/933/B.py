

x, k = map((int), input().split())

answer = []


def findBit(l, r, x, pwk):
    for i in range(0, k):
        if (l + pwk * i <= x and x <= pwk * i + r):
            return i
    return 0

def rec(l, r, pwk):
    global x
    global k
    global answer
    nk = pwk * (k - 1)
    stepL = min(0, nk)
    stepR = max(0, nk)
    nl = l + stepL
    nr = r + stepR
    if (nl <= x and x <= nr):
        answer.append(findBit(l, r, x, pwk))
        x -= answer[-1] * pwk
    else:
        rec(nl, nr, pwk * (-k))
        answer.append(findBit(l, r, x, pwk))
        x -= answer[-1] * pwk
    

rec(0, 0, 1)


print(len(answer))
for x in reversed(answer):
    print(x, end = ' ')
    
print()