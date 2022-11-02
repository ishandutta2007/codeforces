t = int(input())
for i in range(t):
    s = input()
    if s.endswith("po"):
        print("FILIPINO")
    elif s.endswith("mnida"):
        print("KOREAN")
    else:
        print("JAPANESE")