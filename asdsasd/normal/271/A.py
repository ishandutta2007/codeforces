import sys
input = sys.stdin.readline

def main():
    y = int(input())
    while 1:
        y += 1
        if len(set(list(str(y)))) == 4:
            print(y)
            return
    
main()