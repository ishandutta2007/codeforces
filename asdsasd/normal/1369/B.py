import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = input().strip()
    pre = ""
    for s in S:
        if s == "0":
            pre += s
        else:
            break
    suf = ""
    for s in S[::-1]:
        if s == "1":
            suf += s
        else:
            break
    
    if len(pre) + len(suf) == n:
        print(pre + suf)
    else:
        print(pre + "0" + suf)
    
for _ in range(int(input())):
    main()