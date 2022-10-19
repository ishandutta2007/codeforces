import sys

class Desc:
    def __init__(self, c, s):
        self.c = c
        if len(s) >= 4:
            self.pref = s[:4]
            self.suff = s[-4:]
        else:
            self.pref = s
            self.suff = s
    def debug(self):
        print(self.c, self.pref, self.suff)

def prod(u, v):
    ans = Desc(u.c+v.c, u.pref+v.suff)
    for i in range(1, 4):
        if len(u.suff) >= i and len(v.pref) >= 4-i:
            if u.suff[-i:] == "haha"[:i] and v.pref[:4-i] == "haha"[-4+i:]:
                ans.c += 1
    return ans

def convert(s):
    return Desc(1 if "haha" in s else 0, s)

t = int(input())
for _ in range(t):
    n = int(input())
    var = {}
    for k in range(n):
        inst = input()
        if ":" in inst:
            name = inst[:inst.index(":")-1]
            value = inst[inst.index(":")+3:]
            var[name] = convert(value)
        else:
            name = inst[:inst.index("=")-1]
            left = inst[inst.index("=")+2:inst.index("+")-1]
            right = inst[inst.index("+")+2:]
            var[name] = prod(var[left], var[right])
        if k == n-1:
            print(var[name].c)