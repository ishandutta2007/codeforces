def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()


def ask(a,b):

    maxsuma = 0
    suma = 0
    for x in a:
        suma +=  x
        if suma > maxsuma:
            maxsuma = suma

    maxsumb = 0
    sumb = 0
    for x in b:
        sumb += x
        if sumb > maxsumb:
            maxsumb = sumb

    return maxsuma + maxsumb


t = readInt()
for _ in range(t):
    a = readInt()
    aa = readLine()
    b = readInt()
    bb = readLine()

    print(ask(aa,bb))