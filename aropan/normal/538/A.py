#!/usr/bin/python
# -*- coding: utf-8 -*-


def main():
    s = raw_input()
    n = len(s)
    for i in range(0, n + 1):
        for j in range(i, n + 1):
            if s[:i] + s[j:] == "CODEFORCES":
                print "YES"
                return
    print "NO"

if __name__ == "__main__":
    main()