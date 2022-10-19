import sys
input = sys.stdin.readline

def main():
    alst = list(map(int, input().split()))
    print(4 - len(set(alst)))
    
main()