import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    if 1 in alst:
        print("HARD")
    else:
        print("EASY")
    
main()