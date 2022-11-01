

s = """+------------------------+
|#.#.#.#.#.#.#.#.#.#.#.|D|)
|#.#.#.#.#.#.#.#.#.#.#.|.|
|#.......................|
|#.#.#.#.#.#.#.#.#.#.#.|.|)
+------------------------+"""

s =  [list(i) for i in s.split("\n")]

k = int(raw_input())

ans = []
for j in xrange(25):
    for i in xrange(1,5):
        if k > 0 and s[i][j] == "#":
            k -= 1
            s[i][j] = "O"

s = "\n".join("".join(i for i in x) for x in s)
print s