original = raw_input()

mapping = {
    ">": "1000",
    "<": "1001",
    "+": "1010",
    "-": "1011",
    ".": "1100",
    ",": "1101",
    "[": "1110",
    "]": "1111"
    }

binary = "".join(mapping[x] for x in original)
print int(binary, 2) % 1000003