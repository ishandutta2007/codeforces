import sys
input = sys.stdin.readline

def main():
    n = int(input())
    s_s = ["I hate", "I love"]
    ans = ""
    for i in range(n - 1):
        ans += s_s[i % 2]
        ans += " that "
    ans += s_s[(n - 1) % 2]
    ans += " it"
    print(ans)
    
main()