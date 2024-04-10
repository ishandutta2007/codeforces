import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    tot = 0
    fi = 5
    se = 5
    for i, s in enumerate(S, 1):
        if i % 2 == 1:
            fi -= 1
            if s != "0":
                tot += 1
        else:
            se -= 1
            if s == "1":
                tot -= 1
        if tot > se:
            break
    ans1 = i
    tot = 0
    fi = 5
    se = 5
    for i, s in enumerate(S, 1):
        if i % 2 == 1:
            fi -= 1
            if s == "1":
                tot -= 1
        else:
            se -= 1
            if s != "0":
                tot += 1
        if tot > fi:
            break
    print(min(ans1, i))
    
for _ in range(int(input())):
    main()