import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    blst = list(map(int, input().split()))
    s = set(alst[1:] + blst[1:])
    if len(s) == n:
        print("I become the guy.")
    else:
        print("Oh, my keyboard!")
    
main()