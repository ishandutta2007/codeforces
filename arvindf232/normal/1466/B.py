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
    count = 0
    lookingFor = 1

    for i in st:
        if lookingFor > i+1:
            continue

        elif lookingFor >= i:
            count += 1
            lookingFor += 1
            continue
        else:
            count += 1
            lookingFor = i + 1
            continue

    return count

if __name__ == "__main__":
    # Write your solution here

    t = readInt()

    for _ in range(t):
        n = readInt()
        things = readLine()
        print(ask(things))
    pass