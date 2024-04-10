import sys

def isVowel(ch):
    return ch in "AOYEUI" or ch in "aoyeui"

str = sys.stdin.readline()
str = str.rstrip(" \n")

for ch in str:
    if not isVowel(ch):
        sys.stdout.write("." + ch.lower())
sys.stdout.flush()