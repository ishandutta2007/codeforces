"""
Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
"""
def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()


def ask(n,weights,Q):
    degs = {}

    def addDeg(v):
        degs[v] = degs.get(v,0) + 1

    for a,b in Q:
        addDeg(a)
        addDeg(b)

    ret = []
    for key,value in degs.items():
        if(value == 1):
            continue

        ap = weights[key-1]
        for _ in range(value - 1):
            ret.append(ap)

    base = sum(weights)
    sot = sorted(ret,reverse=True)

    ret = [base]
    for ti in sot:
        base += ti
        ret.append(base)

    return ret

# import time


if __name__ == "__main__":
    # t0 = time.time()
    # ask(200000,[1 for _ in range(200000)],[(1,2) for _ in range(200000)])
    # t1 = time.time()
    # print(t1-t0)

    t= readInt()
    for _ in range(t):
        n = readInt()
        weights = readLine()

        Q = []
        for __ in range(n-1):
            a,b = readLine()
            Q.append((a,b))

        ans = ask(n,weights,Q)
        print(" ".join([str(a) for a in ans]))



    pass


# Connected comopnetsn disections
# splittings?

# n colougrinsr 1,2,3,4,5,?????