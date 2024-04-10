import sys
input = sys.stdin.readline

def main():
    s1, s2, s3, s4 = map(int, input().split())
    if min(s1, s2) > max(s3, s4) or max(s1, s2) < min(s3, s4):
        print("NO")
    else:
        print("YES")
    
    
for _ in range(int(input())):
    main()