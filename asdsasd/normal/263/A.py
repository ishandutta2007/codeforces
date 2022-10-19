import sys
input = sys.stdin.readline

def main():
    tizu = [list(map(int, input().split())) for _ in range(5)]
    for i in range(5):
        if 1 in tizu[i]:
            ind = tizu[i].index(1)
            print(abs(i - 2) + abs(ind - 2))
            return

main()