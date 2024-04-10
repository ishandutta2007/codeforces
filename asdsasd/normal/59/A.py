import sys
input = sys.stdin.readline

def main():
    s = input().strip()
    up = 0
    lo = 0
    for ss in s:
        if ss.upper() == ss:
            up += 1
        else:
            lo += 1
    if lo >= up:
        print(s.lower())
    else:
        print(s.upper())
main()