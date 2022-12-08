P = [0] * 2001
S = [[] for i in range(2001)]
q = [list(map(int,raw_input().split())) + [str(i + 1)] for i in range(input())]
q.sort(key=lambda q: q[1])
for t, d, p, i in q:
    for x in range(t, d)[::-1]:
        if P[x] < P[x - t] + p:
            P[x] = P[x - t] + p
            S[x] = S[x - t] + [i]
k = P.index(max(P))
print('\n'.join([str(P[k]), str(len(S[k])), ' '.join(S[k])]))