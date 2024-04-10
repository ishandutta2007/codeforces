def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()

def ask(arr):
    p1 = 0
    p2 = len(arr) -1
    alt = True

    returning = []

    while True:
        if (p1 == p2):
            returning.append(arr[p1])
            return returning

        if alt:
            returning.append(arr[p1])
            p1 += 1
        else:
            returning.append(arr[p2])
            p2 -= 1



        alt = not alt


t = readInt()
for i in range(t):
    s = readInt()
    sts = readLine()

    result = ask(sts)
    print(" ".join([str(x) for x in result]))