
def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()

def ask(rook,n):
    # print(rook,n)
    def NOTEQ(a):
        return a[0] != a[1]

    rooks = [a for a in rook if NOTEQ(a)]

    stuff = {a:b for a,b in rooks}


    firstIndex = set([a for a,b in rooks])
    total = 0
    while firstIndex:
        x = firstIndex.pop()
        firstIndex.add(x)

        explored = set()
        explored.add(x)

        next = x
        while True:
            next = stuff[next]
            if next not in firstIndex:
                total += len(explored)
                firstIndex.difference_update(explored)
                break
            elif next in explored:
                total += len(explored) + 1
                firstIndex.difference_update(explored)
                break
            else:
                explored.add(next)
                continue

    return total





if __name__ == "__main__":
    # Write your solution here
    t = readInt()

    for _ in range(t):
        n,m = readLine()
        ret = []
        for _ in range(m):
            a,b = readLine()
            ret.append((a,b))

        print(ask(ret,n))


    pass