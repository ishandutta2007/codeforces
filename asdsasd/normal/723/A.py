import sys
input = sys.stdin.readline

def main():
    lst = list(map(int, input().split()))
    print(max(lst) - min(lst))
    
main()
"""
for _ in range(int(input())):
    main()
"""