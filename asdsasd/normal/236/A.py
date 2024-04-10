import sys
input = sys.stdin.readline

def main():
    s = input().strip()
    l = len(set(list(s)))
    if l % 2 == 0:
        print("CHAT WITH HER!")
    else:
        print("IGNORE HIM!")

main()