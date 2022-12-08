import sys

def no():
    print('NO')
    sys.exit(0)
def align(s, t, i, j):
    if i < j:
        i, j = j, i
        s, t = t, s
    result = s[:i - j]
    s = s[i - j:]
    for k in range(max(len(s), len(t))):
        if k < len(s) and k < len(t):
            if s[k] != t[k]:
                no()
        result += s[k] if k < len(s) else t[k]
    return result
n = input()
s = set()
for i in range(n):
    cur = raw_input()
    if len(set(cur)) != len(cur):
        no()
    any_changes = True
    while any_changes:
        any_changes = False
        for x in s:
            if set(x) & set(cur):
                any_changes = True
                min_new_string = None
                s.remove(x)
                for i in range(len(x)):
                    for j in range(len(cur)):
                        if x[i] != cur[j]:
                            continue
                        t = align(x, cur, i, j)
                        if len(set(t)) == len(t) and (min_new_string 
                                is None or min_new_string > t):
                            min_new_string = t
                if min_new_string is None:
                    no()
                cur = min_new_string
                break
    s.add(cur)
print(''.join(sorted(s)))