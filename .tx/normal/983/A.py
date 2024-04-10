import sys

def main():
    n = int(input())
    ans = []
    for i in range(n):
        p, q, b = map(int, input().split(" "))
        t = pow(b, 111, q)
        if p * t % q == 0:
            ans.append("Finite")
        else:
            ans.append("Infinite")

    print("\n".join(ans))

main()