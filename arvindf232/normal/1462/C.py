def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]


def eatNumber(x):
    y = x
    returning = ""
    for i in range(9,0,-1):
        if(y > i):
            returning = str(i) + returning
            y -= i
            continue

        else:
            return str(y) + returning

    if y > 0:
        return -1
    else:
        return returning


t = readInt()

for s in range(t):
    st = readInt()

    print(eatNumber(st))