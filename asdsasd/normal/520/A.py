import sys
input = sys.stdin.readline

def main():
    _ = input()
    dic = {}
    for s in input().strip():
        dic[s.lower()] = 1
    if len(dic) == 26:
        print("YES")
    else:
        print("NO")
    
main()
"""
for _ in range(int(input())):
    main()
"""