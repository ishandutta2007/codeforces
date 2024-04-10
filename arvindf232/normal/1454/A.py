def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()

def ask(s):
    ret = []
    for i in range(2,s+1,1):
        ret.append(i)

    ret.append(1)
    return ret

t = readInt()
for i in range(t):
    s = readInt()
    ret = ask(s)
    print(" ".join([str(x) for x in ret]))