def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()

t = readInt()

def minAsks(su):
    st = sorted(su)
    median = st[len(su)//2]

    ret = 0
    for i in st:
        ret += abs(i - median)

    return ret

def ask(ma):
    m = len(ma)
    n = len(ma[0])
    total = 0
    for i in range((m+1)//2):
        for j in range((n+1)//2 ):

            if(2 * i + 1 == m):
                p1 = [i]
            else:
                p1 = [i,m-1-i]

            if(2* j + 1 == n ):
                p2 = [j]
            else:
                p2= [j,n-1-j]

            tocount = []
            for p in p1:
                for st in p2:
                    tocount.append(ma[p][st])

            total += minAsks(tocount)

    return total


for _ in range(t):
    m, n = readLine()
    ret = []
    for _ in range(m):
        ret.append(readLine())

    print(ask(ret))