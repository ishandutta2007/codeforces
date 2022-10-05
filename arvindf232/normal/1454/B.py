



def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()

def ask(st):

    occ = {}

    for i in range(len(st)):
        var = st[i]
        if not var in occ:
            occ[var] = i

        elif occ[var] == -1:
            continue

        else:
            occ[var] = -1



    things = {k:v for (k,v) in occ.items() if v != -1}
    if not things:
        return -1

    smallest = min(things.keys())
    return things[smallest] + 1



t = readInt()
for i in range(t):
    s = readInt()
    st = readLine()
    ret = ask(st)
    print(ret)