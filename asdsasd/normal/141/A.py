import sys
input = sys.stdin.readline

def main():
    s1 = input().strip()
    s = list(s1 + input().strip())
    t = list(input().strip())
    s.sort()
    t.sort()
    if s == t:
        print("YES")
    else:
        print("NO")
    
main()
"""
for _ in range(int(input())):
    main()
"""