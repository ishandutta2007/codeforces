import sys
input = sys.stdin.readline

def main():
    n1 = input().strip()
    n2 = input().strip()
    ans = ""
    for i, j in zip(n1, n2):
        ans += str(int(i) ^ int(j))
    print(ans)
    
    
main()