def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()


def ask(ar,Lfirst):

    if sum(ar) % 2 == 1 :
        return False

    if ar[0] == 0 and not Lfirst:
        return False

    if ar[2] == 0 and not Lfirst:
        return False

    return True


t = readInt()
for  _ in range(t):
    st = input()

    Lfirst = False
    seen = False
    ret = []
    current =0

    for c in st:
        if(c == "("):
            if not seen:
                seen = True
                Lfirst = True
            ret.append(current)
            current = 0

        if (c == ")"):
            if not seen:
                seen = True
                Lfirst = False
            ret.append(current)
            current = 0

        if(c == "?"):
            current += 1

    ret.append(current)
    result = ask(ret,Lfirst)
    if result:
        print("YES")
    else:
        print("NO")