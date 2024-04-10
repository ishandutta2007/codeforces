"""
Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
"""
def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()

def ask(st):

    p2 = None
    p1 = None
    now = None

    ret = set()
    for i in range(len(st)):
        s = st[i]
        p2 = p1
        p1 = now
        now = s

        c2 = (now == p2)
        c1 = (now == p1)

        if c2 and not (i-2) in ret:
            ret.add(i)

        if c1 and not (i-1) in ret:
            ret.add(i)

    return len(ret)






if __name__ == "__main__":

    t = readInt()
    for _ in range(t):
        s = input()
        print(ask(s))
    # Write your solution here
    pass


# can we assume there is always a safe word

# palidrome with middle/double intevral
# just kill the middle thing

# just kill all aa and a-a
# states: changed 1 2 3 4