"""
Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
"""


def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()

def ask(st):
    things = set()

    for i in st:
        for j in st:
            things.add(j-i)

    return (len(things) - 1) // 2


if __name__ == "__main__":
    t = readInt()

    for _ in range(t):
        n = readInt()
        st = readLine()
        print(ask(st))
    # Write your solution here
    pass