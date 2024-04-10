

def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()

t = readInt()


def ask(s):

    first = True
    ret = {}
    previous = -1
    for i in s:

        ret[i] = ret.get(i, 0)
        # print(i,previous)
        if(i == previous):
            previous = i
            continue

        if(first):
            previous = i
            first = False
            continue

        previous = i
        # print(ret)

        ret[i] = ret.get(i,0) + 1


    ret[s[-1]] = ret.get(s[-1],0)
    ret[s[-1]] -= 1

    # print(ret.values())
    return min(ret.values()) + 1


for i in range(t):
    n  = readInt()
    s = readLine()

    result = ask(s)
    print(result)