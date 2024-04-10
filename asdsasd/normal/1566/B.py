import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    if "0" not in S:
        print(0)
        return
    elif "1" not in S:
        print(1)
        return
    cnt = 0
    bef = "1"
    for s in S:
        if s != bef:
            cnt += 1
            bef = s
    if cnt >= 3:
        print(2)
    else:
        print(1)
    
for _ in range(int(input())):
    main()