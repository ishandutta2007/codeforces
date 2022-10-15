#!/usr/bin/python
# -*- coding: utf-8 -*-

def main():
    n = input()
    a = [
        "+------------------------+",
        "|O.O.O.#.#.#.#.#.#.#.#.|D|)",
        "|O.O.O.#.#.#.#.#.#.#.#.|.|",
        "|O.......................|",
        "|O.O.#.#.#.#.#.#.#.#.#.|.|)",
        "+------------------------+",
    ]
    for j in range(50):
        for i in range(len(a)):
            arr = list(a[i])
            if j < len(arr) and arr[j] in ['O', '#']:
                arr[j] = 'O' if n > 0 else '#'
                n -= 1
            a[i] = ''.join(arr)
    print '\n'.join(a)

if __name__ == "__main__":
    main()