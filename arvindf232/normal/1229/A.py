
def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

students = readInt()
knowledge = readLine()
skills = readLine()

def contains(sub:int,super:int):
    return ((sub&(~super))) == 0

def exist(zip,func):
    for element in zip:
        if func(element):
            return True

    return False


skillCount = {}
for a in knowledge:
    if a in skillCount:
        skillCount[a] += 1
    else:
        skillCount[a] = 1

leaderKnowledge = [key for key, value in skillCount.items() if value >= 2]
result = 0
for i in range(students):
    myknowledge = knowledge[i]
    if( exist(leaderKnowledge, lambda over:contains(myknowledge, over))):
        result += skills[i]

print(result)