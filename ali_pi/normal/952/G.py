data = raw_input()
lens = [(256 - ord(data[0]))]
for i in range(len(data) - 1):
    lens.append((512 - (ord(data[i+1]) - ord(data[i]))) % 256)
line0 = "." * 512
line1 = ".X" + ("." * 510)
for i in range(len(data)):
    if lens[i] == 0:
        print(line1)
    else:
        print(line0)
        print(".X" * lens[i] + ".." * (256 - lens[i]))
        print(line1)