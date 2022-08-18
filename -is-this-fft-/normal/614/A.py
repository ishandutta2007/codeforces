# Python since r*k doesn't fit in long long...

inp = input().split(" ")
left = int(inp[0])
right = int(inp[1])
base = int(inp[2])

powers = [1]
while powers[-1] < right:
    powers.append(powers[-1] * base)

outp = []
for i in powers:
    if left <= i and i <= right:
        outp.append(i)

if len(outp) == 0:
    print(-1)
else:
    for i, val in enumerate(outp):
        print(val, end="")
        if i == len(outp) - 1:
            print()
        else:
            print(" ", end="")