t = int(input())

l = 'RSP'
r = 'PRS'

def solve():
    s = input()
    cnt = [0] * 3
    for c in s:
        for j in range(3):
            if l[j] == c:
                cnt[j] += 1
    print(r[cnt.index(max(cnt))] * len(s))

for test in range(t):
    solve()