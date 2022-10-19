import sys
input = sys.stdin.readline

def main():
    alst = list(map(int, input().split()))
    if alst[1] == 0:
        if alst[0] == 0:
            print("1" * (alst[2] + 1))
        else:
            print("0" * (alst[0] + 1))
    else:
        s = "0" * (alst[0] + 1) + "1" * (alst[2] + 1)
        n = alst[1] - 1
        zo = {"0":"1", "1":"0"}
        for _ in range(n):
            s += zo[s[-1]]
        print(s)
        
        
    
for _ in range(int(input())):
    main()