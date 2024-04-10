class State:
  __slots__ = ['candidate', 'votes', 'last_vote']

  def __init__(self, cand, votes, last):
    self.candidate = cand
    self.votes = votes
    self.last_vote = last

  def beats(self, other, extra):
    return self.votes + extra > other.votes

def main():
  candidates, seats, people, voted = map(int, raw_input().split())
  votes = [0 for i in range(candidates)]
  last_vote = [0 for i in range(candidates)]

  if candidates == 1:
    print(1)
    return

  v = list(map(int,raw_input().split()))
  for t in range(voted):
    cand = v[t] - 1
    votes[cand] += 1
    last_vote[cand] = t

  states = [State(i, votes[i], last_vote[i]) for i in range(candidates)]
  states = sorted(states, key = lambda x : (x.votes, -x.last_vote))
  res = [0 for i in range(candidates)]

  for i in range(candidates):
    if i < candidates - seats:
      low = candidates - seats
      if states[i].beats(states[low], people - voted):
        res[states[i].candidate] = 2
      else:
        res[states[i].candidate] = 3
    else:
      extra = people - voted
      other = i - 1
      place = i

      if extra == 0 and states[i].votes == 0:
        res[states[i].candidate] = 3
        continue

      while other >= 0 and extra > 0:
        needed = states[i].votes - states[other].votes + 1
        if needed <= extra:
          extra -= needed;
          place -= 1
          other -= 1
        else:
          break
      res[states[i].candidate] = (1 if place + seats >= candidates and states[i].votes > 0 else 2)
  for i in res:
    print i;end = ' '

main()