import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    T = input().strip()
    l = len(T)
    for i in range(1, l + 1):
        t1 = T[:i]
        t2 = T[i-1:][::-1]
        j = l + 1 - i
        if len(t1) >= len(t2):
            if t1 in S and t1[-j:] == t2:
                print("Yes")
                return
        else:
            if t2 in S and t1 == t2[-i:]:
                print("Yes")
                return
    print("No")
    
for _ in range(int(input())):
    main()