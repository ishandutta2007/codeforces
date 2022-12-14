#input = open("input.txt").readline
#f = open("output.txt", "w")

def greedy(le, su):
    if su > le * 9:
        return None
    l = []
    while su > 0:
        if su <= 9:
            l.append(su)
            su = 0
        else:
            l.append(9)
            su -= 9
    for i in range(le - len(l)):
        l.append(0)
    return l[::-1]


def get(li):
    st = ""
    for i in li:
        st += str(i)
    if st == "":
        st = "0"
    return st


mi = [0]  # mi is OK ans
mi_str = "0"

const = "9" * 500

n = int(input())

for i in range(n):
    s = int(input())
    for j in range(len(mi), -1, -1):
        begin = mi[:j]
        begin_sum = sum(begin)
        mi_can = const
        for dig in range(1, 10):
            if begin_sum + dig > s:
                continue
            g = greedy(len(mi) - j - 1, s - begin_sum - dig)
            if g is None:
                continue
            if begin_sum + dig + sum(g) != s:
                continue
            g = begin + [dig] + g
            g_str = get(g)
            if int(mi_str) <= int(g_str) < int(mi_can):
                mi_can = g_str
                continue
        if mi_can != const:
            print(mi_can)
            mi_str = str(int(mi_can) + 1)
            mi = list(map(int, mi_str))
            break
    else:
        g_str = const
        for dig in range(1, 10):
            g = greedy(len(mi), s - dig)
            c = 1
            while g is None:
                g = greedy(len(mi) + c, s - dig)
                c += 1
            g = [dig] + g
            can = get(g)
            if int(can) < int(g_str):
                g_str = can
        mi_str = g_str
        print(mi_str)
        mi_str = str(int(mi_str) + 1)
        mi = list(map(int, mi_str))