import sys
input = sys.stdin.readline

def main():
    lst = list(input().strip().split("+"))
    lst.sort()
    print("+".join(lst))

main()