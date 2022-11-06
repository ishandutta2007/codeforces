def beats(a, b):
    return a == "rock" and b == "scissors" or a == "scissors" and b == "paper" or a == "paper" and b == "rock"

s = [input(), input(), input()]

if beats(s[0], s[1]) and beats(s[0], s[2]):
    print("F")
elif beats(s[1], s[0]) and beats(s[1], s[2]):
    print("M")
elif beats(s[2], s[0]) and beats(s[2], s[1]):
    print("S")
else:
    print("?")