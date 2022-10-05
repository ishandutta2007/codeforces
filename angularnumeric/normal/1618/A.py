import sys
input = sys.stdin.readline


def main():
    t = int(input())
    for _ in range(t):
        B = [int(x) for x in input().split()]

        for i in range(7):
            for j in range(i + 1, 7):
                for k in range(j + 1, 7):
                    x = B[i]
                    y = B[j]
                    z = B[k]

                    if x + y + z == B[-1]:
                        print(x, y, z)
                        break
                else:
                    continue
                break
            else:
                continue
            break



        
    

if __name__ == '__main__':
    main()