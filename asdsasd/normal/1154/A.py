import sys
input = sys.stdin.readline

def main():
    lst = list(map(int, input().split()))
    lst.sort()
    print(lst[-1] - lst[0], lst[-1] - lst[1], lst[-1] - lst[2])

main()
"""
for _ in range(int(input())):
    main()
"""