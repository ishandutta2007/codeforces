s, v1, v2, t1, t2 = map(int, input().split())
s1 = s * v1 + 2 * t1
s2 = s * v2 + 2 * t2
if s1 == s2:
    print("Friendship")
elif s1 < s2:
    print("First")
else:
    print("Second")