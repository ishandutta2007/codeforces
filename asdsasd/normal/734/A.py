import sys
input = sys.stdin.readline

def main():
    n = int(input())
    s = input().strip()
    a = s.count("A")
    d = s.count("D")
    if a > d:
        print("Anton")
    elif a == d:
        print("Friendship")
    else:
        print("Danik")
    
main()