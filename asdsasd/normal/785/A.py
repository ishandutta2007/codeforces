import sys
input = sys.stdin.readline

def main():
    dic = {"Tetrahedron":4, "Cube":6, "Octahedron":8, 
        "Dodecahedron":12, "Icosahedron":20}
    ans = 0
    for _ in range(int(input())):
        ans += dic[input().strip()]
    print(ans)

main()