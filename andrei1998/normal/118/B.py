import sys 

n = int(sys.stdin.readline())

for i in range(0, n + 1): 
    for j in range(1, n - i +1):
        sys.stdout.write("  ")
    for j in range(0, i + 1): 
        sys.stdout.write(str(j))
        if j < i:
            sys.stdout.write(" ")
    for j in reversed(range(0, i)):
        sys.stdout.write(" " + str(j))
    print

for i in reversed(range(0, n)):
    for j in range(1, n - i +1):
        sys.stdout.write("  ")
    for j in range(0, i + 1): 
        sys.stdout.write(str(j))
        if j < i:
            sys.stdout.write(" ")
    for j in reversed(range(0, i)):
        sys.stdout.write(" " + str(j))
    print

sys.stdout.flush()