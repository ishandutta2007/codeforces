
def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()

def isGoodPivot(k,n):
    s1 = k
    s2 = n
    S1 = s1>s2
    while True:
        if S1:
            s1 = -(s1 // -s2)
        else:
            s2 = -(s2 // -s1)

        S1 = not S1

        if(min(s1,s2) == 1):
            if(max(s1,s2)==2):
                return True
            else:
                return False

from math import sqrt,ceil
def calPath(n):
    y = lambda x: ceil(sqrt(x))
    ret = []
    while(n > 2):
        n = y(n)
        ret.append(n)

    # print(ret)
    return ret


def ask(n):
    path = calPath(n)
    stuff = set(path)

    # pivot = choosePivot(n)
    ret = []

    for i in range(2,n,1):
        if i in stuff:
            continue
        ret.append((i,n))

    last = n
    for t in path:
        ret.append((last,t))
        ret.append((last, t))
        last = t
    # s1 = n
    # s2 = pivot

    # S1 = True
    # while min(s1,s2) != 1 or max(s1,s2) != 2:
    #     # if(s1 > s2):
    #     #     S1 = True
    #     # else:
    #     #     S1 = False
    #
    #     if S1:
    #         ret.append((n,pivot))
    #         S1 = not S1
    #         s1 = -(s1 // -s2)
    #     else:
    #         ret.append((pivot, n))
    #         S1 = not S1
    #         s2 = -(s2 // -s1)
    #
    #
    # # print("Len" len(ret))
    return ret



t = readInt()
for _ in range(t):
    n = readInt()
    result = ask(n)
    print(len(result))
    for a,b in result:
        print(a,b)

    # print(len(result))