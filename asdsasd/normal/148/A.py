import sys
input = sys.stdin.readline

def main():
    alst = [int(input()) for _ in range(4)]
    d = int(input())
    tf = [False for _ in range(d)]

    for a in alst:
        if a > d:
            continue
        if tf[a - 1]:
            continue
        for i in range(a - 1, d, a):
            tf[i] = True

    print(tf.count(True))
    
main()