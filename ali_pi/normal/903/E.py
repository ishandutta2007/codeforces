from collections import Counter
from itertools import permutations

k, n = map(int,raw_input().split())
s = list(set([raw_input() for _ in xrange(k)]))
k = len(s)

if k == 1:
    print(s[0][1] + s[0][0] + s[0][2:])
    exit(0)


def no():
    print(-1)
    exit(0)


def check(string):
    for ss in s:
        count = 0
        for i in xrange(n):
            if ss[i] != string[i]:
                count += 1
        if not (count == 2 or (count == 0 and flag)):
            return False
    return True


def comm(correct1, diff_val1, correct2, diff_val2):
    for i in xrange(n):
        if correct2[i] == '*':
            if correct1[i] != '*':
                correct2[i] = correct1[i]
                diff_val2[correct1[i]] -= 1
                if diff_val2[correct1[i]] == -1:
                    no()
        else:
            if correct1[i] == '*':
                diff_val1[correct2[i]] -= 1
                if diff_val1[correct2[i]] == -1:
                    no()
            else:
                if correct1[i] != correct2[i]:
                    no()
    if len(diff_val2 - diff_val1) != 0 or len(diff_val1 - diff_val2) != 0:
        no()


def diff(a, b):
    diff_val1 = Counter()
    diff_val2 = Counter()
    right = []
    for i in xrange(n):
        if a[i] != b[i]:
            diff_val1[a[i]] += 1
            diff_val2[b[i]] += 1
            right.append('*')
        else:
            right.append(a[i])
    if len(diff_val1) > 4 or len(diff_val1) == 1 or diff_val1 != diff_val2:
        no()
    return right, diff_val2


correct = ['*'] * n
values = Counter(list(s[0]))
flag = (max(values.values()) > 1)

same, diff_val = diff(s[0], s[1])
comm(same, diff_val, correct, values)

t = []
for v in values:
    t += [v] * values[v]

for p in permutations(t):
    p = list(p)
    ans = ""
    for i in xrange(n):
        ans += correct[i] if correct[i] != '*' else p.pop()
    if check(ans):
        print(ans)
        exit(0)
no()